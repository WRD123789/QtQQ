#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "talkwindowshell.h"

#include <QObject>

// 窗口管理器
class WindowManager : public QObject
{
    Q_OBJECT
public:
    WindowManager();
    ~WindowManager();

public:
    QWidget* findWindow(const QString &windowID);             // 在管理器中查找窗口
    void deleteWindow(const QString &windowID);               // 将指定窗口移出管理器
    void addWindow(const QString &windowID, QWidget *widget); // 将指定窗口加入管理器
    void addNewTalkWindow(const QString &windowID);           // 添加新的对话窗口
    inline TalkWindowShell* getTalkWindowShell() { return m_talkWindowShell; }
    inline QString getCreatingTalkWindowID() { return m_creatingTalkWindowID; }

    static WindowManager* getInstance();

private:
    TalkWindowShell *m_talkWindowShell;
    QMap<QString, QWidget *> m_windowMap; // 窗口 ID 和窗口之间的映射
    QString m_creatingTalkWindowID;       // 正在创建的聊天窗口的窗口号
};

#endif // WINDOWMANAGER_H
