#include "userlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    UserLogin *userLogin = new UserLogin;
    userLogin->show();

    return a.exec();
}
