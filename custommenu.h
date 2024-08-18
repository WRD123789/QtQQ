#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QMenu>
#include <QWidget>
#include <QMap>

// 系统托盘右击时弹出的自定义菜单
class CustomMenu : public QMenu {
    Q_OBJECT
public:
    CustomMenu(QWidget *parent = nullptr);
    ~CustomMenu();

public:
    void addCustomMenu(const QString &text, const QString &icon, const QString &name);
    QAction* getAction(const QString &text);

private:
    QMap<QString, QAction*> m_menuActionMap;
};

#endif // CUSTOMMENU_H
