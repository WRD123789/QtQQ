#include "talkwindowshell.h"
#include "./ui_talkwindowshell.h"
#include "./ui_talkwindow.h"
#include "commonutils.h"
#include "talkwindow.h"
#include "talkwindowitem.h"
#include "windowmanager.h"
#include "qmsgtextedit.h"
#include "receivefile.h"

#include <QFile>
#include <QMessageBox>
#include <QSettings>
#include <QSqlQuery>
#include <QChar>
#include <QRegularExpression>

extern QString gLoginEmployeeID;
QString gFileName;
QString gFileData;
const int gTcpPort = 8888;
const int gUdpProt = 6666;

TalkWindowShell::TalkWindowShell(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::TalkWindowClass)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initControl();
    initTcpSocket();
    initUdpSocket();

    QStringList employeeList = getAllEmployeeID();
    if (!createJsFile(employeeList)) {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("更新 JS 文件数据失败!"));
    }
}

TalkWindowShell::~TalkWindowShell()
{
    delete m_emotionWindow;
    m_emotionWindow = nullptr;
}

void TalkWindowShell::addTalkWindow(TalkWindow *talkWindow, TalkWindowItem *talkWindowItem, const QString &windowID)
{
    ui->rightStackedWidget->addWidget(talkWindow);

    connect(m_emotionWindow, &EmotionWindow::signalEmotionWindowHide,
            talkWindow, &TalkWindow::onSetEmotionBtnStatus);

    // 关联左侧的列表项与聊天窗口
    QListWidgetItem *aItem = new QListWidgetItem(ui->listWidget);
    m_talkWindowItemMap.insert(aItem, talkWindow);

    aItem->setSelected(true);

    // 判断是群聊还是单聊
    QSqlQuery query;
    QString sqlStr = QString("SELECT picture "
                             "FROM tab_department "
                             "WHERE departmentID = %1").arg(windowID);
    query.exec(sqlStr);
    if (query.next()) {
        talkWindowItem->setHeadPixmap(query.value(0).toString());
    } else {
        sqlStr = QString("SELECT picture "
                         "FROM tab_employees "
                         "WHERE employeeID = %1").arg(windowID);
        query.exec(sqlStr);
        query.next();
        talkWindowItem->setHeadPixmap(query.value(0).toString());
    }

    ui->listWidget->addItem(aItem);
    ui->listWidget->setItemWidget(aItem, talkWindowItem);

    onTalkWindowItemClicked(aItem);

    connect(talkWindowItem, &TalkWindowItem::signalCloseClicked,
            this, [talkWindowItem, talkWindow, aItem, this] {
        m_talkWindowItemMap.remove(aItem);
        ui->listWidget->takeItem(ui->listWidget->row(aItem));
        delete talkWindowItem;

        talkWindow->close();
        ui->rightStackedWidget->removeWidget(talkWindow);

        // 不存在聊天窗口时, 关闭 `TalkWindowShell`
        if (ui->rightStackedWidget->count() < 1)
            close();
    });
}

void TalkWindowShell::setCurrentWidget(QWidget *widget)
{
    ui->rightStackedWidget->setCurrentWidget(widget);
}

const QMap<QListWidgetItem *, QWidget *> &TalkWindowShell::getTalkWindowItemMap() const
{
    return m_talkWindowItemMap;
}

void TalkWindowShell::initControl()
{
    loadStyleSheet("TalkWindow");
    setWindowTitle(QString::fromLocal8Bit("聊天窗口"));

    m_emotionWindow = new EmotionWindow;
    m_emotionWindow->hide();

    // 分类器进行尺寸划分
    QList<int> sizeList;
    sizeList << 154 << width() - 154;
    ui->splitter->setSizes(sizeList);

    ui->listWidget->setStyle(new CustomProxyStyle(this));

    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &TalkWindowShell::onTalkWindowItemClicked);
    connect(m_emotionWindow, SIGNAL(signalEmotionItemClicked(int)),
            this, SLOT(onEmotionItemClicked(int)));
}

void TalkWindowShell::initTcpSocket()
{
    m_tcpClientSocket = new QTcpSocket(this);
    m_tcpClientSocket->connectToHost("127.0.0.1", gTcpPort);
}

void TalkWindowShell::initUdpSocket()
{
    m_udpReceiver = new QUdpSocket(this);

    // 尝试绑定一个端口
    for (quint16 port = gUdpProt; port < gUdpProt + 200; port += 1) {
        if (m_udpReceiver->bind(port)) {
            qDebug() << port;
            break;
        }
    }

    connect(m_udpReceiver, &QUdpSocket::readyRead,
            this, &TalkWindowShell::processPendingData);
}

bool TalkWindowShell::createJsFile(QStringList &employeeList)
{
    QString txtFilePath = ":/Resources/MainWindow/MsgHtml/msgtmpl.txt";
    QFile fileRead(txtFilePath);
    QString readData;
    if (fileRead.open(QIODevice::ReadOnly)) {
        readData = fileRead.readAll();
        fileRead.close();
    } else {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("文件 msgtmpl.txt 读取失败!"));
        return false;
    }

    // msgtmpl.js 中, external0、appendHtml0 用于发送数据
    // 替换 external、appendHtml 为 external_employeeID、appendHtml_employeeID, 用于接收其他用户的数据
    QString jsFilePath = "../../../../../Resources/MainWindow/MsgHtml/msgtmpl.js";
    QFile fileWrite(jsFilePath);
    if (fileWrite.open(QIODevice::WriteOnly | QIODevice::Truncate)) { // 清空原文件
        // 准备替换
        QString sourceInitNull = "var external = null;";
        QString sourceInit = "external = channel.objects.external;";
        QString sourceRecvHtml;
        QFile readRecvHtml(":/Resources/MainWindow/MsgHtml/recvHtml.txt");
        if (readRecvHtml.open(QIODevice::ReadOnly)) {
            sourceRecvHtml = readRecvHtml.readAll();
            readRecvHtml.close();
        } else {
            QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                     QString::fromLocal8Bit("文件 recvHtml.txt 读取失败!"));
            return false;
        }

        // 保存替换后的脚本内容
        QString replaceInitNull, replaceInit, replaceRecvHtml;
        for (int i = 0; i < employeeList.length(); i += 1) {
            QString tempInitNull = sourceInitNull;
            tempInitNull.replace("external", QString("external_%1").arg(employeeList.at(i)));
            replaceInitNull += tempInitNull + "\n";

            QString tempInit = sourceInit;
            tempInit.replace("external", QString("external_%1").arg(employeeList.at(i)));
            replaceInit += tempInit + "\n";

            QString tempRecvHtml = sourceRecvHtml;
            tempRecvHtml.replace("external", QString("external_%1").arg(employeeList.at(i)));
            tempRecvHtml.replace("recvHtml", QString("recvHtml_%1").arg(employeeList.at(i)));
            replaceRecvHtml += tempRecvHtml + "\n";
        }

        readData.replace(sourceInitNull, replaceInitNull);
        readData.replace(sourceInit, replaceInit);
        readData.replace(sourceRecvHtml, replaceRecvHtml);

        // 将替换后的数据写入 msgtmpl.js 中
        QTextStream stream(&fileWrite);
        stream << readData;

        fileWrite.close();

        return true;
    } else {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("文件 msgtmpl.js 写入失败!"));
        return false;
    }
}

QStringList TalkWindowShell::getAllEmployeeID()
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT employeeID "
                             "FROM tab_employees "
                             "WHERE status = 1");
    query.exec(sqlStr);

    QStringList list;
    while (query.next())
        list.append(query.value(0).toString());

    return list;
}

bool TalkWindowShell::isDepartment(QString &windowID)
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT * "
                             "FROM tab_department "
                             "WHERE departmentID = %1").arg(windowID);
    query.exec(sqlStr);

    if (query.next())
        return true;
    else
        return false;
}

void TalkWindowShell::handleReceiveMsg(int senderEmployeeID, int msgType, QString msg)
{
    QMsgTextEdit msgTextEdit;
    msgTextEdit.setText(msg);

    if (msgType == 1) {
        msgTextEdit.document()->toHtml();
    } else if (msgType == 0) {
        const int emotionWidth = 3;
        int emotionNum = msg.length() / emotionWidth;

        for (int i = 0; i < emotionNum; i += 1)
            msgTextEdit.addEmotionUrl(msg.mid(i * emotionWidth, emotionWidth).toInt());
    }

    QString html = msgTextEdit.document()->toHtml();

    static QRegularExpression regex(R"(/>\s*[^<]*\s*</p>)");
    html.replace(regex, R"(/></p>)");

    TalkWindow *talkWindow = dynamic_cast<TalkWindow*>(ui->rightStackedWidget->currentWidget());
    talkWindow->ui->msgWidget->appendMsg(html, QString::number(senderEmployeeID));
}

void TalkWindowShell::onEmotionBtnClicked(bool)
{
    m_emotionWindow->setVisible(!m_emotionWindow->isVisible());

    // 移动表情窗口到合适的位置
    QPoint emotionPoint = this->mapToGlobal(QPoint(0, 0)); // 获取当前窗口左上角相对于整个屏幕的位置 (局部坐标转换为全局坐标)
    emotionPoint.setX(emotionPoint.x() + 170);
    emotionPoint.setY(emotionPoint.y() + 220);
    m_emotionWindow->move(emotionPoint);
}

// msgType: 0 表情, 1 文本, 2 文件
void TalkWindowShell::updateSendMsg(QString &msg, int &msgType, QString fileName)
{
    TalkWindow *curTalkWindow = dynamic_cast<TalkWindow*>(ui->rightStackedWidget->currentWidget());
    QString windowID = curTalkWindow->getWindowID();

    QString groupFlag; // 群聊标志, 1 群聊, 0 单聊
    if (isDepartment(windowID))
        groupFlag = "1";
    else
        groupFlag = "0";

    int dataLength = msg.length();
    int lenghtWidth = QString::number(dataLength).length(); // 数据长度的宽度
    QString strDataLength;
    QString sendData;

    // 保证数据长度的宽度始终为 5 位, 方便服务端取出数据长度
    if (msgType == 1) {
        // 发送文本信息
        // 文本数据包格式: 群聊标志 + 发信息员工号 + 收信息员工号/群号 + 数据类型 + 数据长度 + 数据
        if (lenghtWidth == 1)
            strDataLength = "0000" + QString::number(dataLength);
        else if (lenghtWidth == 2)
            strDataLength = "000" + QString::number(dataLength);
        else if (lenghtWidth == 3)
            strDataLength = "00" + QString::number(dataLength);
        else if (lenghtWidth == 4)
            strDataLength = "0" + QString::number(dataLength);
        else if (lenghtWidth == 5)
            strDataLength = QString::number(dataLength);
        else
            QMessageBox::information(this, QString("提示"),
                                     QString::fromLocal8Bit("不合理的数据长度!"));

        sendData = groupFlag + gLoginEmployeeID + windowID + "1" + strDataLength + msg;
    } else if (msgType == 0) {
        // 发送表情信息
        // 表情数据包格式: 群聊标志 + 发信息员工号 + 收信息员工号/群聊 + 数据类型 + 表情个数 + "images" + 数据
        sendData = groupFlag + gLoginEmployeeID + windowID + "0" + msg;
    } else if (msgType == 2) {
        // 发送文件信息
        // 文件数据包格式: 群聊标志 + 发信息员工号 + 收信息员工号/群聊 +
        // 数据类型 + 文件长度 + "bytes" + 文件名称 + "data_begin" + 文件内容
        QByteArray array = msg.toUtf8();
        QString fileLength = QString::number(array.length());
        sendData = groupFlag + gLoginEmployeeID + windowID + "2" + fileLength + "bytes" +
                   fileName + "data_begin" + msg;
    }

    QByteArray dataArray;
    dataArray.resize(sendData.length());
    dataArray = sendData.toUtf8();
    m_tcpClientSocket->write(dataArray);
}

void TalkWindowShell::onTalkWindowItemClicked(QListWidgetItem *item)
{
    QWidget *talkWindow = m_talkWindowItemMap.value(item);
    ui->rightStackedWidget->setCurrentWidget(talkWindow);
}

void TalkWindowShell::onEmotionItemClicked(int emotionNum)
{
    TalkWindow *curTalkWindow = dynamic_cast<TalkWindow*>(ui->rightStackedWidget->currentWidget());
    if (curTalkWindow)
        curTalkWindow->addEmotionImage(emotionNum);
}

void TalkWindowShell::processPendingData()
{
    // 有未处理的数据
    while (m_udpReceiver->hasPendingDatagrams()) {
        const static int groupFlagWidth = 1;  // 群聊标志占 1 个字符
        const static int groupWidth = 4;      // 群聊号占 4 个字符
        const static int employeeIDWidth = 4; // 员工号占 4 个字符
        const static int msgTypeWidth = 1;    // 消息类型占 1 个字符
        const static int msgLengthWidth = 5;  // 文本信息长度的占 5 个字符
        const static int emotionWidth = 3;    // 表情名的占 3 个字符串

        // 从 UDP Socket 中读取数据
        QByteArray receiveData;
        receiveData.resize(m_udpReceiver->pendingDatagramSize());
        m_udpReceiver->readDatagram(receiveData.data(), receiveData.size());

        QString data = receiveData.data();
        QString windowID; // 群聊时为群号, 单聊时为员工号
        QString sendEmployeeID, receiveEmployeeID;
        QString fileName;
        QString msg;
        int msgLength;
        QChar msgType;

        sendEmployeeID = data.mid(groupFlagWidth, employeeIDWidth);

        // 自己发的信息不处理
        if (sendEmployeeID == gLoginEmployeeID)
            return;

        if (data[0] == '1') {
            // 群聊
            windowID = data.mid(groupFlagWidth + employeeIDWidth, groupWidth);
            msgType = data[groupFlagWidth + employeeIDWidth + groupWidth];

            if (msgType == '1') {
                // 处理文本信息
                msgLength = data.mid(groupFlagWidth + employeeIDWidth + groupWidth +
                                         msgTypeWidth, msgLengthWidth).toInt();
                msg = data.mid(groupFlagWidth + employeeIDWidth + groupWidth +
                                   msgTypeWidth + msgLengthWidth, msgLength);
            } else if (msgType == '0') {
                // 处理表情信息
                int pos = data.indexOf("images");
                msg = data.right(data.length() - pos - QString("images").length());
            } else {
                // 处理文件信息
                int bytesWidth = QString("bytes").length();
                int posBytes = data.indexOf("bytes");
                int dataBeginWidth = QString("data_begin").length();
                int posDataBegin = data.indexOf("data_begin");

                fileName = data.mid(posBytes + bytesWidth, posDataBegin - posBytes - bytesWidth);
                gFileName = fileName;
                msg = data.mid(posDataBegin + dataBeginWidth);
                gFileData = msg;

                // 根据 employeeID 获取发送者名称
                QString senderName;
                QSqlQuery query;
                QString sqlStr = QString("SELECT employee_name "
                                         "FROM tab_employees "
                                         "WHERE employeeID = %1").arg(sendEmployeeID.toInt());
                query.exec(sqlStr);
                query.next();
                senderName = query.value(0).toString();

                ReceiveFile *receiveFile = new ReceiveFile(this);

                connect(receiveFile, &ReceiveFile::refuseFile, [this] {
                    return;
                });

                QString msgLabel = QString("收到来自 %1 发来的文件, 是否接收? ").arg(senderName);
                receiveFile->setMsg(msgLabel);
                receiveFile->show();
            }
        } else {
            // 单聊
            receiveEmployeeID = data.mid(groupFlagWidth + employeeIDWidth, employeeIDWidth);
            windowID = sendEmployeeID;

            // 不是发给自己的信息
            if (receiveEmployeeID != gLoginEmployeeID)
                return;

            msgType = data[groupFlagWidth + employeeIDWidth + employeeIDWidth];
            if (msgType == '1') {
                // 处理文本信息
                msgLength = data.mid(groupFlagWidth + employeeIDWidth + employeeIDWidth +
                                         msgTypeWidth, msgLengthWidth).toInt();
                msg = data.mid(groupFlagWidth + employeeIDWidth + employeeIDWidth +
                                   msgTypeWidth + msgLengthWidth, msgLength);
            } else if (msgType == '0') {
                // 处理表情信息
                int pos = data.indexOf("images");
                msg = data.right(data.length() - pos - QString("images").length());
            } else {
                // 处理文件信息
                int bytesWidth = QString("bytes").length();
                int posBytes = data.indexOf("bytes");
                int dataBeginWidth = QString("data_begin").length();
                int posDataBegin = data.indexOf("data_begin");

                fileName = data.mid(posBytes + bytesWidth, posDataBegin - posBytes - bytesWidth);
                gFileName = fileName;
                msg = data.mid(posDataBegin + dataBeginWidth);
                gFileData = msg;

                QSqlQuery query;
                QString sqlStr = QString("SELECT employee_name "
                                         "FROM tab_employees "
                                         "WHERE employeeID = %1").arg(sendEmployeeID.toInt());
                query.exec(sqlStr);
                query.next();
                QString senderName = query.value(0).toString();

                ReceiveFile *receiveFile = new ReceiveFile(this);

                connect(receiveFile, &ReceiveFile::refuseFile, [this] {
                    return;
                });

                QString msgLabel = QString("收到来自 %1 发来的文件, 是否接收? ").arg(senderName);
                receiveFile->setMsg(msgLabel);
                receiveFile->show();
            }
        }

        // 将聊天窗口设置为活动窗口
        QWidget *widget = WindowManager::getInstance()->findWindow(windowID);
        if (widget) {
            this->setCurrentWidget(widget);

            QListWidgetItem *item = m_talkWindowItemMap.key(widget);
            item->setSelected(true);
        } else {
            return;
        }

        // 文件信息另作处理
        if (msgType != '2')
            handleReceiveMsg(sendEmployeeID.toInt(), msgType.digitValue(), msg);
    }
}
