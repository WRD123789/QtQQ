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
    void addNewTalkWindow(const QString &windowID, GroupType groupType = COMPANY,
                          const QString &strPeople = "");     // 添加新的对话窗口

    static WindowManager* getInstance();

private:
    TalkWindowShell *m_talkWindowShell;
    QMap<QString, QWidget *> m_windowMap; // 窗口 ID 和窗口之间的映射
};

#endif // WINDOWMANAGER_H
