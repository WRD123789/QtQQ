#include "receivefile.h"
#include "./ui_receivefile.h"

#include <QFileDialog>
#include <QMessageBox>

extern QString gFileName;
extern QString gFileData;

ReceiveFile::ReceiveFile(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::ReceiveFile)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initTitleBar();
    setTitleBarTitle("", ":/Resources/MainWindow/qqlogoclassic.png");
    loadStyleSheet("SendFile");

    this->move(100, 400);

    connect(ui->okBtn, &QPushButton::clicked, this, &ReceiveFile::onOkBtnClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &ReceiveFile::onCancelBtnClicked);
    connect(_titleBar, &TitleBar::signalButtonCloseClicked, this, &ReceiveFile::refuseFile);
}

void ReceiveFile::setMsg(QString &msg)
{
    ui->label->setText(msg);
}

void ReceiveFile::onOkBtnClicked()
{
    close();

    // 获取保存文件的路径
    QString fileDirPath = QFileDialog::getExistingDirectory(
        nullptr,
        "文件保存路径",
        "/"
    );
    QString filePath = fileDirPath + "/" + gFileName;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(gFileData.toUtf8());
        file.close();

        QMessageBox::information(nullptr, "提示", "文件接收成功!");
    } else {
        QMessageBox::information(nullptr, "提示", "文件接收失败!");
    }
}


void ReceiveFile::onCancelBtnClicked()
{
    emit refuseFile();

    close();
}

