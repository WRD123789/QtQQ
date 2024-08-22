#include "userlogin.h"
#include "./ui_userlogin.h"
#include "ccmainwindow.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

QString gLoginEmployeeID; // 登录者的员工号

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
    QPixmap srcPic(":/Resources/MainWindow/app/logo.ico");
    QPixmap maskPic(":/Resources/MainWindow/head_mask.png");
    headLabel->setPixmap(getRoundImage(srcPic, maskPic, headLabel->size()));
    headLabel->move(width() / 2 - 34, ui->titleWidget->height() - 34);

    connect(ui->loginBtn, &QPushButton::clicked, this, &UserLogin::onLoginBtnClicked);

    if (!connectDatabase()) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("连接数据库失败!"));
        close();
    }
}

bool UserLogin::connectDatabase()
{
    // 数据库连接设置
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qtqq");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("162738609");
    db.setPort(3306);

    if (!db.open())
        return false;

    return true;
}

bool UserLogin::verifyAccount(bool &isAccountLogin, QString &account)
{
    QString userInput = ui->editUserAccount->text();
    QString passwordInput = ui->editPassword->text();

    QSqlQuery query;
    // 可以选择用员工号或账号登录
    // 尝试用员工号登录
    QString sqlStr = QString("SELECT password "
                             "FROM tab_accounts "
                             "WHERE employeeID = '%1'").arg(userInput);
    query.exec(sqlStr);

    if (query.next()) {
        QString password = query.value(0).toString();

        if (password == passwordInput) {
            gLoginEmployeeID = userInput;
            account = userInput;
            isAccountLogin = false;
            return true;
        } else {
            return false;
        }
    }

    // 尝试用账号登录
    sqlStr = QString("SELECT password, employeeID "
                     "FROM tab_accounts "
                     "WHERE account = '%1'").arg(userInput);
    query.exec(sqlStr);

    if (query.next()) {
        QString password = query.value(0).toString();

        if (password == passwordInput) {
            gLoginEmployeeID = query.value(1).toString();
            account = userInput;
            isAccountLogin = true;
            return true;
        } else {
            return false;
        }
    }

    return false;
}

void UserLogin::onLoginBtnClicked()
{
    bool isAccountLogin;
    QString account;
    // 判断用户输入的账号和密码是否正确
    if (!verifyAccount(isAccountLogin, account)) {
        QMessageBox::warning(NULL, QString::fromLocal8Bit("提示"),
                             QString::fromLocal8Bit("输入的账号或密码有误!"));
        return;
    }

    close();

    CCMainWindow *mainWindow = new CCMainWindow(account, isAccountLogin);
    mainWindow->show();
}
