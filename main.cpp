#include "userlogin.h"

#include <QApplication>
#include <QSqlQuery>

extern QString gLoginEmployeeID;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    UserLogin *userLogin = new UserLogin;
    userLogin->show();

    QObject::connect(qApp, &QApplication::aboutToQuit, [] {
        // 更新登录状态
        QSqlQuery query;
        QString sqlStr = QString("UPDATE tab_employees "
                                 "SET online = 1 "
                                 "WHERE employeeID = %1").arg(gLoginEmployeeID);
        query.exec(sqlStr);
    });

    return a.exec();
}
