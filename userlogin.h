#ifndef USERLOGIN_H
#define USERLOGIN_H

#include "basicwindow.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class UserLogin;
}
QT_END_NAMESPACE

// 登录界面
class UserLogin : public BasicWindow {
    Q_OBJECT
public:
    UserLogin(QWidget *parent = nullptr);
    ~UserLogin();

private slots:
    void onLoginBtnClicked();

private:
    void initControl();
    bool connectDatabase(); // 连接数据库
    bool verifyAccount();   // 验证账号密码

private:
    Ui::UserLogin *ui;
};

#endif // USERLOGIN_H
