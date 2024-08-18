#include "windowmanager.h"
#include "talkwindowitem.h"
#include "talkwindow.h"

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
    if (m_windowMap.contains(windowID))
        m_windowMap.insert(windowID, widget);
}

void WindowManager::addNewTalkWindow(const QString &windowID, GroupType groupType, const QString &strPeople)
{
    if (m_talkWindowShell == nullptr) {
        m_talkWindowShell = new TalkWindowShell;

        connect(m_talkWindowShell, &TalkWindowShell::destroyed, this, [this] {
            m_talkWindowShell = nullptr;
        });
    }

    QWidget *widget = findWindow(windowID);
    if (widget == nullptr) {
        TalkWindow *talkWindow = new TalkWindow(m_talkWindowShell, windowID, groupType);
        TalkWindowItem *talkWindowItem = new TalkWindowItem(talkWindow);

        switch (groupType) {
            case COMPANY:
                talkWindow->setWindowName(QStringLiteral("公司群-测试"));
                talkWindowItem->setMsgLabelContent(QStringLiteral("公司群"));
                break;
            case PERSONELGROUP:
                talkWindow->setWindowName(QStringLiteral("人事部-测试"));
                talkWindowItem->setMsgLabelContent(QStringLiteral("人事部"));
                break;
            case DEVELOPMENTGROUP:
                talkWindow->setWindowName(QStringLiteral("研发部-测试"));
                talkWindowItem->setMsgLabelContent(QStringLiteral("研发部"));
                break;
            case MARKETGROUP:
                talkWindow->setWindowName(QStringLiteral("市场群-测试"));
                talkWindowItem->setMsgLabelContent(QStringLiteral("市场部"));
                break;
            case PTOP:
                talkWindow->setWindowName(QStringLiteral("市场群-测试"));
                talkWindowItem->setMsgLabelContent(QStringLiteral("市场部"));
                break;
            default:
                break;
        }

        m_talkWindowShell->addTalkWindow(talkWindow, talkWindowItem, groupType);
    } else {
        m_talkWindowShell->setCurrentWidget(widget);
    }

    m_talkWindowShell->show();
    m_talkWindowShell->activateWindow();
}

WindowManager *WindowManager::getInstance()
{
    return theInstance;
}
