#include "talkwindow.h"
#include "./ui_talkwindow.h"
#include "rootcontactitem.h"
#include "contactitem.h"
#include "commonutils.h"
#include "windowmanager.h"

#include <QFile>
#include <QMessageBox>
#include <QSqlQuery>
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

}

void TalkWindow::initTalkWindow()
{

}

void TalkWindow::initPToPTalk()
{
    QPixmap pix(":/Resources/MainWindow/skin.png");
    ui->widget->setFixedSize(pix.size());

    QLabel *skinLabel = new QLabel(ui->widget);
    skinLabel->setPixmap(pix);
    skinLabel->setFixedSize(ui->widget->size());
}

void TalkWindow::addPeopleInfo(QTreeWidgetItem *pRootGroupItem)
{
    QTreeWidgetItem *pChild = new QTreeWidgetItem;

    pChild->setData(0, Qt::UserRole, 1);
    pChild->setData(0, Qt::UserRole + 1, QString::number(quintptr(pChild)));

    ContactItem *pContactItem = new ContactItem(ui->treeWidget);
    QPixmap head_mask(":/Resources/MainWindow/head_mask.png");
    QPixmap head = CommonUtils::getRoundImage(QPixmap(":/Resources/MainWindow/head.jpg"),
                                 head_mask, pContactItem->getHeadLabelSize());
    pContactItem->setHeadPixmap(head);

    // 临时静态数据
    static int i = 0;
    pContactItem->setUserName(QString::fromLocal8Bit("测试%1").arg(i++));
    pContactItem->setSignName(QString::fromLocal8Bit(""));

    pRootGroupItem->addChild(pChild);
    ui->treeWidget->setItemWidget(pChild, 0, pContactItem);

    QString peopleName = pContactItem->getUserName();
    m_groupPeopleMap.insert(pChild, peopleName);
}
