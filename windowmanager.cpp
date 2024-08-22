#include "windowmanager.h"
#include "talkwindowitem.h"
#include "talkwindow.h"

#include <QSqlQuery>

// 创建全局静态对象
Q_GLOBAL_STATIC(WindowManager, theInstance)

WindowManager::WindowManager()
    : QObject{nullptr}
    , m_talkWindowShell{nullptr}
{}

WindowManager::~WindowManager()
{}

QWidget *WindowManager::findWindow(const QString &windowID)
{
    if (m_windowMap.contains(windowID))
        return m_windowMap.value(windowID);

    return nullptr;
}

void WindowManager::deleteWindow(const QString &windowID)
{
    m_windowMap.remove(windowID);
}

void WindowManager::addWindow(const QString &windowID, QWidget *widget)
{
    if (!m_windowMap.contains(windowID))
        m_windowMap.insert(windowID, widget);
}

void WindowManager::addNewTalkWindow(const QString &windowID)
{
    if (m_talkWindowShell == nullptr) {
        m_talkWindowShell = new TalkWindowShell;

        connect(m_talkWindowShell, &TalkWindowShell::destroyed, this, [this] {
            m_talkWindowShell = nullptr;
        });
    }

    QWidget *widget = findWindow(windowID);
    if (widget == nullptr) {
        TalkWindow *talkWindow = new TalkWindow(m_talkWindowShell, windowID);
        TalkWindowItem *talkWindowItem = new TalkWindowItem(talkWindow);

        QSqlQuery query;
        QString sqlStr = QString("SELECT department_name, sign "
                                 "FROM tab_department "
                                 "WHERE departmentID = %1").arg(windowID);
        query.exec(sqlStr);
        // 判断是单聊还是群聊
        if (query.next()) {
            talkWindow->setWindowName(query.value(1).toString());
            talkWindowItem->setMsgLabelContent(query.value(0).toString());
        } else {
            sqlStr = QString("SELECT employee_name, employee_sign "
                             "FROM tab_employees "
                             "WHERE employeeID = %1").arg(windowID);
            query.exec(sqlStr);
            query.next();
            talkWindow->setWindowName(query.value(1).toString());
            talkWindowItem->setMsgLabelContent(query.value(0).toString());
        }

        m_talkWindowShell->addTalkWindow(talkWindow, talkWindowItem, windowID);
    } else {
        // 将左侧聊天列表中对应的项设置为选中状态
        QListWidgetItem *item = m_talkWindowShell->getTalkWindowItemMap().key(widget);
        item->setSelected(true);

        m_talkWindowShell->setCurrentWidget(widget);
    }

    m_talkWindowShell->show();
    m_talkWindowShell->activateWindow();
}

WindowManager *WindowManager::getInstance()
{
    return theInstance;
}
