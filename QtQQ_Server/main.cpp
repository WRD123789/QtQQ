#include "qtqqserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtQQServer w;
    w.show();
    return a.exec();
}
