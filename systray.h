#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QSystemTrayIcon>
#include <QWidget>

// 系统托盘
class SysTray : public QSystemTrayIcon {
    Q_OBJECT
public:
    SysTray(QWidget *parent);
    ~SysTray();

private:
    void initSystemTray();
    void addSysTrayMenu(); // 添加系统托盘菜单

public slots:
    void onIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    QWidget *m_parent;
};

#endif // SYSTRAY_H
