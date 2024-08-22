#include "talkwindow.h"
#include "./ui_talkwindow.h"
#include "rootcontactitem.h"
#include "contactitem.h"
#include "commonutils.h"
#include "windowmanager.h"

#include <QFile>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QToolTip>

TalkWindow::TalkWindow(QWidget *parent, const QString &windowID)
    : QWidget{parent}
    , ui(new Ui::TalkWindow)
    , m_windowID(windowID)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initGroupTalkStatus();
    initControl();
}

TalkWindow::~TalkWindow()
{
    WindowManager::getInstance()->deleteWindow(m_windowID);
}

void TalkWindow::addEmotionImage(int emotionNum)
{
    ui->textEdit->setFocus();
    ui->textEdit->addEmotionUrl(emotionNum);
}

void TalkWindow::setWindowName(const QString &name)
{
    ui->nameLabel->setText(name);
}

void TalkWindow::onSetEmotionBtnStatus()
{

}

void TalkWindow::onSendBtnClicked(bool)
{
    if (ui->textEdit->toPlainText().isEmpty()) {
        QToolTip::showText(this->mapToGlobal(QPoint(630, 666)), QString::fromLocal8Bit("发送的信息不能为空!"),
                           this, QRect(0, 0, 120, 100), 2000);

        return;
    }

    // 从 `QTextEdit` 的文档中获取整个文档的 HTML 表示形式
    QString html = ui->textEdit->document()->toHtml();

    ui->textEdit->clear();
    ui->textEdit->deleteAllEmotionImage();

    ui->msgWidget->appendMsg(html); // 在消息窗口中添加信息
}

void TalkWindow::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    bool isChild = item->data(0, Qt::UserRole).toBool();
    if (isChild) {
        QString peopleID = item->data(0, Qt::UserRole + 1).toString();
        WindowManager::getInstance()->addNewTalkWindow(peopleID);
    }

}

void TalkWindow::initControl()
{
    // 设置右边组件的尺寸
    QList<int> rightWidgetSize;
    rightWidgetSize << 600 << 138;
    ui->bodySplitter->setSizes(rightWidgetSize);

    // 设置文本框
    ui->textEdit->setFontPointSize(10);
    ui->textEdit->setFocus();

    connect(ui->sysmin, SIGNAL(clicked(bool)), parent(), SLOT(onShowMin(bool)));
    connect(ui->sysclose, SIGNAL(clicked(bool)), parent(), SLOT(onShowClose(bool)));
    connect(ui->closeBtn, SIGNAL(clicked(bool)), parent(), SLOT(onShowClose(bool)));

    connect(ui->faceBtn, SIGNAL(clicked(bool)), parent(), SLOT(onEmotionBtnClicked(bool)));
    connect(ui->sendBtn, SIGNAL(clicked(bool)), this, SLOT(onSendBtnClicked(bool)));

    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this, SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));

    if (m_isGroupTalk)
        initTalkWindow();
    else
        initPToPTalk();

}

void TalkWindow::initGroupTalkStatus()
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT * "
                             "FROM tab_department "
                             "WHERE departmentID = %1").arg(m_windowID);
    query.exec(sqlStr);
    if (query.next())
        m_isGroupTalk = true;
    else
        m_isGroupTalk = false;
}

int TalkWindow::getCompDepID()
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT departmentID "
                             "FROM tab_department "
                             "WHERE department_name = '公司群'");
    query.exec(sqlStr);
    query.next();

    return query.value(0).toInt();
}

void TalkWindow::initTalkWindow()
{
    // 先构造根项
    QTreeWidgetItem* pRootItem = new QTreeWidgetItem;

    pRootItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    pRootItem->setData(0, Qt::UserRole, 0);

    RootContactItem* pItemName = new RootContactItem(false, ui->treeWidget);

    ui->treeWidget->setFixedHeight(646);

    // 获取群的名称
    QString strGroupName;
    QSqlQuery queryGroupName(QString("SELECT department_name "
                                     "FROM tab_department "
                                     "WHERE departmentID = %1").arg(m_windowID));
    queryGroupName.exec();

    if (queryGroupName.next())
        strGroupName = queryGroupName.value(0).toString();

    QSqlQueryModel queryEmployeeModel;

    // 针对公司群单独处理
    if (getCompDepID() == m_windowID.toInt())
        queryEmployeeModel.setQuery("SELECT employeeID "
                                    "FROM tab_employees "
                                    "WHERE status = 1");
    else
        queryEmployeeModel.setQuery(QString("SELECT employeeID "
                                            "FROM tab_employees "
                                            "WHERE status = 1 "
                                            "AND departmentID = %1")
                                        .arg(m_windowID));

    // 获取群聊中当前员工的数量
    int nEmployeeNum = queryEmployeeModel.rowCount();

    // 设置群聊名称
    QString qsGroupName = QString::fromLocal8Bit("%1 %2/%3")
                              .arg(strGroupName).arg(0).arg(nEmployeeNum);
    pItemName->setText(qsGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootItem);
    ui->treeWidget->setItemWidget(pRootItem, 0, pItemName);

    pRootItem->setExpanded(true);

    for (int i = 0; i < nEmployeeNum; i++) {
        QModelIndex modelindex = queryEmployeeModel.index(i, 0);
        int employeeID = queryEmployeeModel.data(modelindex).toInt();
        addPeopleInfo(pRootItem,employeeID);
    }
}

void TalkWindow::initPToPTalk()
{
    QPixmap pix(":/Resources/MainWindow/skin.png");
    ui->widget->setFixedSize(pix.size());

    QLabel *skinLabel = new QLabel(ui->widget);
    skinLabel->setPixmap(pix);
    skinLabel->setFixedSize(ui->widget->size());
}

void TalkWindow::addPeopleInfo(QTreeWidgetItem *pRootGroupItem, int employeeID)
{
    QTreeWidgetItem *pChild = new QTreeWidgetItem;

    pChild->setData(0, Qt::UserRole, 1);
    pChild->setData(0, Qt::UserRole + 1, employeeID);

    QString userName, sign, headPath;
    QSqlQuery query;
    QString sqlStr = QString("SELECT employee_name, employee_sign, picture "
                             "FROM tab_employees "
                             "WHERE employeeID = %1").arg(employeeID);
    query.exec(sqlStr);
    query.next();
    userName = query.value(0).toString();
    sign = query.value(1).toString();
    headPath = query.value(2).toString();

    ContactItem *pContactItem = new ContactItem(ui->treeWidget);
    QPixmap headMask(":/Resources/MainWindow/head_mask.png");
    QPixmap head = CommonUtils::getRoundImage(QPixmap(headPath),
                                 headMask, pContactItem->getHeadLabelSize());
    pContactItem->setHeadPixmap(head);
    pContactItem->setUserName(userName);
    pContactItem->setSignName(sign);

    pRootGroupItem->addChild(pChild);
    ui->treeWidget->setItemWidget(pChild, 0, pContactItem);

    QString peopleName = pContactItem->getUserName();
    m_groupPeopleMap.insert(pChild, peopleName);
}
