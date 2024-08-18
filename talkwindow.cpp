#include "talkwindow.h"
#include "./ui_talkwindow.h"
#include "rootcontactitem.h"
#include "contactitem.h"
#include "commonutils.h"

TalkWindow::TalkWindow(QWidget *parent, const QString &windowID, GroupType groupType)
    : QWidget{parent}
    , ui(new Ui::TalkWindow)
    , m_windowID(windowID)
    , m_groupType(groupType)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initControl();
}

TalkWindow::~TalkWindow()
{}

void TalkWindow::addEmotionImage(int emotionNum)
{

}

void TalkWindow::setWindowName(const QString &name)
{

}

void TalkWindow::onSetEmotionBtnStatus()
{

}

void TalkWindow::onSendBtnClicked()
{

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

    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            this, SLOT(onItemDoubleClicked(QTreeWidgetItem*, int)));

    switch (m_groupType) {
    case COMPANY:
        initCompanyTalk();
        break;
    case PERSONELGROUP:
        initPersonelTalk();
        break;
    case DEVELOPMENTGROUP:
        initDevelopmentTalk();
        break;
    case MARKETGROUP:
        initMarketTalk();
        break;
    case PTOP:
        initPToPTalk();
        break;
    default:
        break;
    }
}

void TalkWindow::initCompanyTalk()
{
    QTreeWidgetItem *pRootItem = new QTreeWidgetItem;
    pRootItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);

    pRootItem->setData(0, Qt::UserRole, 0);
    RootContactItem *item = new RootContactItem(false, ui->treeWidget);

    ui->treeWidget->setFixedHeight(646); // `TalkWindowShell` 高度 - `TalkWindow` 标题栏的高度

    // 临时静态数据
    int nEmployeeNum = 50;
    QString qsGroupName = QString::fromLocal8Bit("公司群 %1/%2").arg(0).arg(50);
    item->setText(qsGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootItem);
    ui->treeWidget->setItemWidget(pRootItem, 0, item);

    // 设置展开
    pRootItem->setExpanded(true);

    for (int i = 0; i < nEmployeeNum; i += 1)
        addPeopleInfo(pRootItem);
}

void TalkWindow::initPersonelTalk()
{
    QTreeWidgetItem *pRootItem = new QTreeWidgetItem;
    pRootItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);

    pRootItem->setData(0, Qt::UserRole, 0);
    RootContactItem *item = new RootContactItem(false, ui->treeWidget);

    ui->treeWidget->setFixedHeight(646); // `TalkWindowShell` 高度 - `TalkWindow` 标题栏的高度

    // 临时静态数据
    int nEmployeeNum = 30;
    QString qsGroupName = QString::fromLocal8Bit("人事部 %1/%2").arg(2).arg(28);
    item->setText(qsGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootItem);
    ui->treeWidget->setItemWidget(pRootItem, 0, item);

    // 设置展开
    pRootItem->setExpanded(true);

    for (int i = 0; i < nEmployeeNum; i += 1)
        addPeopleInfo(pRootItem);
}

void TalkWindow::initDevelopmentTalk()
{
    QTreeWidgetItem *pRootItem = new QTreeWidgetItem;
    pRootItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);

    pRootItem->setData(0, Qt::UserRole, 0);
    RootContactItem *item = new RootContactItem(false, ui->treeWidget);

    ui->treeWidget->setFixedHeight(646); // `TalkWindowShell` 高度 - `TalkWindow` 标题栏的高度

    // 临时静态数据
    int nEmployeeNum = 77;
    QString qsGroupName = QString::fromLocal8Bit("研发部 %1/%2").arg(0).arg(77);
    item->setText(qsGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootItem);
    ui->treeWidget->setItemWidget(pRootItem, 0, item);

    // 设置展开
    pRootItem->setExpanded(true);

    for (int i = 0; i < nEmployeeNum; i += 1)
        addPeopleInfo(pRootItem);
}

void TalkWindow::initMarketTalk()
{
    QTreeWidgetItem *pRootItem = new QTreeWidgetItem;
    pRootItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);

    pRootItem->setData(0, Qt::UserRole, 0);
    RootContactItem *item = new RootContactItem(false, ui->treeWidget);

    ui->treeWidget->setFixedHeight(646); // `TalkWindowShell` 高度 - `TalkWindow` 标题栏的高度

    // 临时静态数据
    int nEmployeeNum = 20;
    QString qsGroupName = QString::fromLocal8Bit("市场部 %1/%2").arg(9).arg(11);
    item->setText(qsGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootItem);
    ui->treeWidget->setItemWidget(pRootItem, 0, item);

    // 设置展开
    pRootItem->setExpanded(true);

    for (int i = 0; i < nEmployeeNum; i += 1)
        addPeopleInfo(pRootItem);
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
