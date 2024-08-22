#include "ccmainwindow.h"
#include "./ui_ccmainwindow.h"
#include "skinwindow.h"
#include "notifymanager.h"
#include "rootcontactitem.h"
#include "contactitem.h"
#include "talkwindowshell.h"
#include "windowmanager.h"

#include <QProxyStyle>
#include <QPainter>
#include <QTimer>
#include <QApplication>
#include <QSqlQuery>
#include "QMouseEvent"

extern QString gLoginEmployeeID;

class CustomProxyStyle : public QProxyStyle {
public:
    virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
        QPainter *painter, const QWidget *widget = nullptr) const
    {
        if (element == PE_FrameFocusRect)
            return;
        else
            QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

CCMainWindow::CCMainWindow(QString account, bool isAccountLogin, QWidget *parent)
    : BasicWindow(parent)
    , ui(new Ui::CCMainWindow)
{
    ui->setupUi(this);

    m_isAccountLogin = isAccountLogin;
    m_account = account;

    setWindowFlags(windowFlags() | Qt::Tool);
    loadStyleSheet("CCMainWindow");
    initControl();
    initTimer();
}

CCMainWindow::~CCMainWindow()
{
    delete ui;
}

// 初始化定时器, 根据登录时长升级用户等级
void CCMainWindow::initTimer()
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(500);

    connect(timer, &QTimer::timeout, this, [this] {
        static int level = 0;

        if (level == 99)
            level = 0;

        level += 1;
        setLevelPixmap(level);
    });

    timer->start();
}

void CCMainWindow::initControl()
{
    tray = new SysTray(this);

    // 获取焦点时不绘制边框
    ui->treeWidget->setStyle(new CustomProxyStyle);
    QString headPath = getHeadPath();
    setHeadPixmap(headPath);
    setStatusMenuIcon(":/Resources/MainWindow/StatusSucceeded.png");

    // 添加其他 App 图标
    QHBoxLayout *appUpLayout = new QHBoxLayout;
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_7.png", "app_7"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_2.png", "app_2"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_3.png", "app_3"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_4.png", "app_4"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_5.png", "app_5"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_6.png", "app_6"));
    appUpLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/skin.png", "app_skin"));
    appUpLayout->addStretch();
    appUpLayout->setSpacing(2);
    ui->appWidget->setLayout(appUpLayout);

    // 底部添加其他 App 图标
    ui->bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_10.png", "app_10"));
    ui->bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_8.png", "app_8"));
    ui->bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_11.png", "app_11"));
    ui->bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_9.png", "app_9"));
    ui->bottomLayout_up->addStretch();

    initContactTree();

    // 个性签名
    ui->lineEdit->installEventFilter(this);

    // 好友搜索
    ui->searchLineEdit->installEventFilter(this);

    connect(ui->sysmin, &QPushButton::clicked, this, &BasicWindow::onShowMin);
    connect(ui->sysclose, &QPushButton::clicked, this, &BasicWindow::onShowClose);
    connect(NotifyManager::getInstance(), &NotifyManager::signalSkinChanged,
            this, [this] {
        updateSearchStyle();
    });
}

void CCMainWindow::addCompanyDeps(QTreeWidgetItem* pRootGroupItem, int depID)
{
    QTreeWidgetItem *pChild = new QTreeWidgetItem;

    pChild->setData(0, Qt::UserRole, 1);
    pChild->setData(0, Qt::UserRole + 1, depID);

    // 根据部门号获取部门名和头像
    QString sqlStr = QString("SELECT department_name, picture "
                             "FROM tab_department "
                             "WHERE departmentID = %1").arg(depID);
    QSqlQuery query;
    query.exec(sqlStr);
    query.next();
    QString depName = query.value(0).toString();
    QPixmap depHead(query.value(1).toString());

    ContactItem *pContactItem = new ContactItem(ui->treeWidget);
    QPixmap head_mask(":/Resources/MainWindow/head_mask.png");
    QPixmap head = getRoundImage(depHead, head_mask, pContactItem->getHeadLabelSize());
    pContactItem->setHeadPixmap(head);
    pContactItem->setUserName(depName);

    pRootGroupItem->addChild(pChild);
    ui->treeWidget->setItemWidget(pChild, 0, pContactItem);
}

QString CCMainWindow::getHeadPath()
{
    QSqlQuery query;
    QString employeeID;
    if (m_isAccountLogin) {
        QString sqlStr = QString("SELECT employeeID "
                                 "FROM tab_accounts "
                                 "WHERE account = '%1'").arg(m_account);
        query.exec(sqlStr);
        query.next();
        employeeID = query.value(0).toString();
    } else {
        employeeID = m_account;
    }

    QString sqlStr = QString("SELECT picture "
                             "FROM tab_employees "
                             "WHERE employeeID = %1").arg(employeeID);
    query.exec(sqlStr);
    query.next();

    return query.value(0).toString();
}

void CCMainWindow::setUserName()
{
    ui->nameLabel->adjustSize();

    // 获取登录者姓名
    QSqlQuery query;
    QString employeeID;
    if (m_isAccountLogin) {
        QString sqlStr = QString("SELECT employeeID "
                                 "FROM tab_accounts "
                                 "WHERE account = '%1'").arg(m_account);
        query.exec(sqlStr);
        query.next();
        employeeID = query.value(0).toString();
    } else {
        employeeID = m_account;
    }
    QString sqlStr = QString("SELECT employee_name "
                             "FROM tab_employees "
                             "WHERE employeeID = %1").arg(employeeID);
    query.exec(sqlStr);
    query.next();
    QString name = query.value(0).toString();

    // 文本过长时省略
    QString && newName = ui->nameLabel->fontMetrics().elidedText(name, Qt::ElideRight, ui->nameLabel->width());

    ui->nameLabel->setText(newName);
}

// 设置等级
void CCMainWindow::setLevelPixmap(int level)
{
    QPixmap levelPixmap(ui->levelBtn->size());
    levelPixmap.fill(Qt::transparent);

    QPainter painter(&levelPixmap);
    painter.drawPixmap(0, 4, QPixmap(":/Resources/MainWindow/lv.png"));

    int unitNum = level % 10;
    int tenNum = level / 10;

    // 图片中包含 0 ~ 9, 截取图片中的部分进行绘制
    painter.drawPixmap(10, 4, QPixmap(":/Resources/MainWindow/levelvalue.png"),
                       tenNum * 6, 0, 6, 7);
    painter.drawPixmap(16, 4, QPixmap(":/Resources/MainWindow/levelvalue.png"),
                       unitNum * 6, 0, 6, 7);

    ui->levelBtn->setIcon(levelPixmap);
    ui->levelBtn->setIconSize(ui->levelBtn->size());
}

void CCMainWindow::setHeadPixmap(const QString &headPath)
{

    QPixmap srcPix, maskPix;
    srcPix.load(headPath);
    maskPix.load(":/Resources/MainWindow/head_mask.png");

    ui->headLabel->setPixmap(getRoundImage(srcPix, maskPix, ui->headLabel->size()));
}

void CCMainWindow::setStatusMenuIcon(const QString &statusPath)
{
    QPixmap statusPix(ui->statusBtn->size());
    statusPix.fill(Qt::transparent);

    QPainter painter(&statusPix);
    painter.drawPixmap(4, 4, QPixmap(statusPath));

    ui->statusBtn->setIcon(statusPix);
    ui->statusBtn->setIconSize(ui->statusBtn->size());
}

QWidget *CCMainWindow::addOtherAppExtension(const QString &appPath, const QString &appName)
{
    QPushButton *btn = new QPushButton(this);
    btn->setFixedSize(20, 20);

    QPixmap pix(btn->size());
    pix.fill(Qt::transparent);

    QPixmap appPix(appPath);
    QPainter painter(&pix);
    painter.drawPixmap((btn->width() - appPix.width()) / 2,
                       (btn->height() - appPix.height()) / 2, appPix);

    btn->setIcon(appPix);
    btn->setIconSize(btn->size());
    btn->setObjectName(appName);
    btn->setProperty("hasborder", true);

    connect(btn, &QPushButton::clicked, this, &CCMainWindow::onAppIconClicked);

    return btn;
}

void CCMainWindow::initContactTree()
{
    connect(ui->treeWidget, &QTreeWidget::itemClicked,
            this, &CCMainWindow::onItemClicked);             // 单击树中项触发
    connect(ui->treeWidget, &QTreeWidget::itemExpanded,
            this, &CCMainWindow::onItemExpanded);            // 展开树中项触发
    connect(ui->treeWidget, &QTreeWidget::itemCollapsed,
            this, &CCMainWindow::onItemCollapsed);           // 折叠树中项触发
    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked,
            this, &CCMainWindow::onItemDoubleClicked);       // 双击树中的项触发

    // 根节点
    QTreeWidgetItem *pRootGroupItem = new QTreeWidgetItem;
    pRootGroupItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    // 根项数据设置为 0, 子项数据设置为 1
    pRootGroupItem->setData(0, Qt::UserRole, 0);
    // 取消项右边默认的箭头
    ui->treeWidget->setIndentation(0);

    RootContactItem *pItem = new RootContactItem(true, ui->treeWidget);
    QString strGroupName = QString::fromLocal8Bit("聊天分组");
    pItem->setText(strGroupName);

    // 插入分组节点
    ui->treeWidget->addTopLevelItem(pRootGroupItem);
    ui->treeWidget->setItemWidget(pRootGroupItem, 0, pItem);

    QSqlQuery query;
    // 获取公司 ID
    QString sqlStr = QString("SELECT departmentID "
                             "FROM tab_department "
                             "WHERE department_name = '%1'").arg("公司群");
    query.exec(sqlStr);
    query.next();
    int compID = query.value(0).toInt();

    // 获取自己所在的部门 ID
    sqlStr = QString("SELECT departmentID "
                     "FROM tab_employees "
                     "WHERE employeeID = %1").arg(gLoginEmployeeID);
    query.exec(sqlStr);
    query.next();
    int depID = query.value(0).toInt();

    addCompanyDeps(pRootGroupItem, compID);
    addCompanyDeps(pRootGroupItem, depID);
}

void CCMainWindow::updateSearchStyle()
{
    ui->searchWidget->setStyleSheet(QStringLiteral(
        "QWidget#searchWidget{"
        "background-color:rgba(%1,%2,%3,50);"
        "border-bottom:1px solid rgba(%1,%2,%3,30);"
        "}"
        "QPushButton#searchBtn{"
        "image:url(:/Resources/MainWindow/search/search_icon.png);"
        "}")
        .arg(m_colorBackGround.red())
        .arg(m_colorBackGround.green())
        .arg(m_colorBackGround.blue()));
}

void CCMainWindow::resizeEvent(QResizeEvent *event)
{
    setUserName();

    BasicWindow::resizeEvent(event);
}

bool CCMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->searchLineEdit) {
        if (event->type() == QEvent::FocusIn) {
            ui->searchWidget->setStyleSheet(QStringLiteral(
                "QWidget#searchWidget{"
                "background-color:rgb(255,255,255);"
                "border-bottom:1px solid rgba(%1,%2,%3,100);"
                "}"
                "QPushButton#searchBtn{"
                "image:url(:/Resources/MainWindow/search/main_search_deldown.png);"
                "}"
                "QPushButton#searchBtn:hover{"
                "image:url(:/Resources/MainWindow/search/main_search_delhighlight.png);"
                "}"
                "QPushButton#searchBtn:pressed{"
                "image:url(:/Resources/MainWindow/search/main_search_delhighdown.png);"
                "}")
                .arg(m_colorBackGround.red())
                .arg(m_colorBackGround.green())
                .arg(m_colorBackGround.blue()));
        } else if (event->type() == QEvent::FocusOut) {
            updateSearchStyle();
        }
    }

    return false;
}

void CCMainWindow::mousePressEvent(QMouseEvent *event)
{
    // 鼠标按下时的部件如果不是搜索框或签名栏, 取消它们的焦点
    if (qApp->widgetAt(event->pos()) != ui->searchLineEdit && ui->searchLineEdit->hasFocus())
        ui->searchLineEdit->clearFocus();
    else if (qApp->widgetAt(event->pos()) != ui->lineEdit && ui->lineEdit->hasFocus())
            ui->lineEdit->clearFocus();

    BasicWindow::mousePressEvent(event);
}

void CCMainWindow::onAppIconClicked()
{
    if (sender()->objectName() == "app_skin") {
        SkinWindow *skinWindow = new SkinWindow;
        skinWindow->show();
    }
}

void CCMainWindow::onItemClicked(QTreeWidgetItem *item, int column)
{
    bool isChild = item->data(0, Qt::UserRole).toBool();
    if (!isChild)
        // 折叠时展开, 展开时折叠
        item->setExpanded(!item->isExpanded());
}

void CCMainWindow::onItemExpanded(QTreeWidgetItem *item)
{
    bool isChild = item->data(0, Qt::UserRole).toBool();
    if (!isChild) {
        RootContactItem *contactItem = dynamic_cast<RootContactItem*>(ui->treeWidget->itemWidget(item, 0));
        if (contactItem)
            contactItem->setExpanded(true);
    }
}

void CCMainWindow::onItemCollapsed(QTreeWidgetItem *item)
{
    bool isChild = item->data(0, Qt::UserRole).toBool();
    if (!isChild) {
        RootContactItem *contactItem = dynamic_cast<RootContactItem*>(ui->treeWidget->itemWidget(item, 0));
        if (contactItem)
            contactItem->setExpanded(false);
    }
}

void CCMainWindow::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    // 判断是不是 `QTreeWidget` 中的子项
    bool isChild = item->data(0, Qt::UserRole).toBool();
    if (isChild)
        WindowManager::getInstance()->addNewTalkWindow(item->data(0, Qt::UserRole + 1).toString());
}
