#include "systray.h"
#include "custommenu.h"

SysTray::SysTray(QWidget *parent)
    : m_parent(parent)
    , QSystemTrayIcon{parent}
{
    initSystemTray();

    show();
}

SysTray::~SysTray()
{}

void SysTray::initSystemTray()
{
    setToolTip(QStringLiteral("QQ-测试"));
    setIcon(QIcon(":/Resources/MainWindow/app/logo.ico"));

    connect(this, &QSystemTrayIcon::activated, this, &SysTray::onIconActivated);
}

void SysTray::addSysTrayMenu()
{
    CustomMenu *customMenu = new CustomMenu(m_parent);
    customMenu->addCustomMenu("onShow",
                              ":/Resources/MainWindow/app/logo.ico",
                              QStringLiteral("显示"));
    customMenu->addCustomMenu("onQuit",
                              ":/Resources/MainWindow/app/page_close_btn_hover.png",
                              QStringLiteral("退出"));

    connect(customMenu->getAction("onShow"), SIGNAL(triggered(bool)),
            m_parent, SLOT(onShowNormal(bool)));
    connect(customMenu->getAction("onQuit"), SIGNAL(triggered(bool)),
            m_parent, SLOT(onShowQuit(bool)));

    customMenu->exec(QCursor::pos());

    delete customMenu;
    customMenu = nullptr;
}

void SysTray::onIconActivated(ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger) { // 单击
        m_parent->show();
        m_parent->activateWindow();
    } else if (reason == QSystemTrayIcon::Context) { // 右键点击
        addSysTrayMenu();
    }
}
