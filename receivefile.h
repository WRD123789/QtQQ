#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include "basicwindow.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ReceiveFile;
}
QT_END_NAMESPACE

class ReceiveFile : public BasicWindow {
    Q_OBJECT
public:
    ReceiveFile(QWidget *parent = nullptr);

public:
    void setMsg(QString &msg);

private slots:
    void onOkBtnClicked();
    void onCancelBtnClicked();

signals:
    void refuseFile();

private:
    Ui::ReceiveFile *ui;
};

#endif // RECEIVEFILE_H
