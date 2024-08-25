#ifndef TALKWINDOWSHELL_H
#define TALKWINDOWSHELL_H

#include "basicwindow.h"
#include "emotionwindow.h"
#include "talkwindowitem.h"

#include <QWidget>
#include <QListWidgetItem>
#include <QTcpSocket>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class TalkWindowClass;
}
QT_END_NAMESPACE

enum GroupType {
    COMPANY = 0,      // 公司群
    PERSONELGROUP,    // 人事部
    DEVELOPMENTGROUP, // 研发部
    MARKETGROUP,      // 市场部
    PTOP              // 单独聊天
};

class TalkWindow;

// 对话窗口
class TalkWindowShell : public BasicWindow {
    Q_OBJECT
public:
    TalkWindowShell(QWidget *parent = nullptr);
    ~TalkWindowShell();

public:
    // 添加新的聊天窗口
    void addTalkWindow(TalkWindow *talkWindow, TalkWindowItem *talkWindowItem, const QString &windowID);

    // 设置当前聊天窗口
    void setCurrentWidget(QWidget *widget);

    const QMap<QListWidgetItem*, QWidget*>& getTalkWindowItemMap() const;

private:
    void initControl();
    void initTcpSocket(); // 初始化 TCP Socket
    void initUdpSocket(); // 初始化 UDP
    bool createJsFile(QStringList &employeeList);
    QStringList getAllEmployeeID();
    bool isDepartment(QString &windowID);
    void handleReceiveMsg(int senderEmployeeID, int msgType, QString msg);

public slots:
    void onEmotionBtnClicked(bool); // 表情按钮被点击后执行
    // 客户端发送 TCP 数据
    void updateSendMsg(QString &msg, int &msgType, QString fileName = "");

private slots:
    void onTalkWindowItemClicked(QListWidgetItem *item); // 左侧列表点击后执行
    void onEmotionItemClicked(int emotionNum);           // 表情被选中后执行
    void processPendingData();                           // 处理 UDP Socket 收到的数据

private:
    Ui::TalkWindowClass *ui;

    // 打开的聊天窗口
    QMap<QListWidgetItem*, QWidget*> m_talkWindowItemMap;
    // 表情窗口
    EmotionWindow *m_emotionWindow;

private:
    QTcpSocket *m_tcpClientSocket; // TCP Socket
    QUdpSocket *m_udpReceiver;     // UDP Socket
};

#endif // TALKWINDOWSHELL_H
