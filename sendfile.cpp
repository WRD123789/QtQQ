#include "sendfile.h"
#include "./ui_sendfile.h"
#include "windowmanager.h"

#include <QFileDialog>
#include <QMessageBox>

SendFile::SendFile(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::SendFile)
    , m_filePath("")
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initTitleBar();
    setTitleBarTitle("", ":/Resources/MainWindow/qqlogoclassic.png");
    loadStyleSheet("SendFile");

    this->move(100, 400);

    TalkWindowShell *talkWindowShell = WindowManager::getInstance()->getTalkWindowShell();

    connect(this, &SendFile::sendFileClicked, talkWindowShell, &TalkWindowShell::updateSendMsg);
    connect(ui->openBtn, &QPushButton::clicked, this, &SendFile::onOpenBtnClicked);
    connect(ui->sendBtn, &QPushButton::clicked, this, &SendFile::onSendBtnClicked);
}

SendFile::~SendFile()
{}

void SendFile::onOpenBtnClicked()
{
    m_filePath = QFileDialog::getOpenFileName(
        this,
        QString::fromLocal8Bit("选择文件"),
        "/",
        QString::fromLocal8Bit("发送的文件(*.txt *.doc);;所有文件(*.*);;")
    );
    ui->lineEdit->setText(m_filePath);
}


void SendFile::onSendBtnClicked()
{
    if (!m_filePath.isEmpty()) {
        QFile file(m_filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QString fileContent = file.readAll();
            int msgType = 2;

            QFileInfo fileInfo(m_filePath);
            QString fileName = fileInfo.fileName();

            emit sendFileClicked(fileContent, msgType, fileName);

            file.close();
        } else {
            QMessageBox::information(this, "提示", QString::fromLocal8Bit("发送文件 %1 失败!").arg(m_filePath));
            m_filePath = "";
            ui->lineEdit->clear();

            close();
            return;
        }

        m_filePath = "";
        close();
    }
}

