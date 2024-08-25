#ifndef SENDFILE_H
#define SENDFILE_H

#include "basicwindow.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SendFile;
}
QT_END_NAMESPACE

// 发送文件
class SendFile : public BasicWindow {
    Q_OBJECT
public:
    SendFile(QWidget *parent = nullptr);
    ~SendFile();

private slots:
    void onOpenBtnClicked();
    void onSendBtnClicked();

signals:
    void sendFileClicked(QString &data, int &msgType, QString fileName);

private:
    Ui::SendFile *ui;
    QString m_filePath;
};

#endif // SENDFILE_H
