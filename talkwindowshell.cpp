#include "talkwindowshell.h"
#include "./ui_talkwindowshell.h"
#include "commonutils.h"
#include "talkwindow.h"
#include "talkwindowitem.h"

#include <QFile>
#include <QMessageBox>
#include <QSettings>
#include <QSqlQuery>
#include <QDir>

const int gTcpPort = 6666;

TalkWindowShell::TalkWindowShell(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::TalkWindowClass)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initControl();
    initTcpSocket();

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

void TalkWindowShell::onEmotionBtnClicked(bool)
{
    m_emotionWindow->setVisible(!m_emotionWindow->isVisible());

    // 移动表情窗口到合适的位置
    QPoint emotionPoint = this->mapToGlobal(QPoint(0, 0)); // 获取当前窗口左上角相对于整个屏幕的位置 (局部坐标转换为全局坐标)
    emotionPoint.setX(emotionPoint.x() + 170);
    emotionPoint.setY(emotionPoint.y() + 220);
    m_emotionWindow->move(emotionPoint);
}

void TalkWindowShell::updateSendMsg(QString &msg, int &msgType, QString file)
{

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
