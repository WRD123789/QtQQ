#include "userlogin.h"
#include "./ui_userlogin.h"
#include "ccmainwindow.h"

UserLogin::UserLogin(QWidget *parent)
    : BasicWindow(parent)
    , ui(new Ui::UserLogin)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initTitleBar();
    setTitleBarTitle("", ":/Resources/MainWindow/qqlogoclassic.png");
    loadStyleSheet("UserLogin");
    initControl();
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::initControl()
{
    // 设置圆形头像
    QLabel *headLabel = new QLabel(this);
    headLabel->setFixedSize(QSize(68, 68));
    QPixmap srcPic(":/Resources/MainWindow/head.jpg");
    QPixmap maskPic(":/Resources/MainWindow/head_mask.png");
    headLabel->setPixmap(getRoundImage(srcPic, maskPic, headLabel->size()));
    headLabel->move(width() / 2 - 34, ui->titleWidget->height() - 34);

    connect(ui->loginBtn, &QPushButton::clicked, this, &UserLogin::onLoginBtnClicked);
}

void UserLogin::onLoginBtnClicked()
{
    close();

    CCMainWindow *mainWindow = new CCMainWindow;
    mainWindow->show();
}
