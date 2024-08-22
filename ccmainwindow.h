#ifndef CCMAINWINDOW_H
#define CCMAINWINDOW_H

#include "basicwindow.h"
#include "systray.h"

#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CCMainWindow;
}
QT_END_NAMESPACE

// 主窗口
class CCMainWindow : public BasicWindow {
    Q_OBJECT

public:
    CCMainWindow(QString account, bool isAccountLogin, QWidget *parent = nullptr);
    ~CCMainWindow();

public:
    void setUserName();             // 设置用户名
    void setLevelPixmap(int level);                    // 设置等级
    void setHeadPixmap(const QString &headPath);       // 设置头像
    void setStatusMenuIcon(const QString &statusPath); // 设置状态

    QWidget *addOtherAppExtension(const QString &appPath, const QString &appName); // 添加其他应用部件
    void initContactTree();

private:
    void updateSearchStyle(); // 更新搜索样式
    void initTimer();         // 初始化计时器
    void initControl();       // 初始化控件
    void addCompanyDeps(QTreeWidgetItem* pRootGroupItem, int depID); // 添加部门群聊
    QString getHeadPath();

private:
    void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void onAppIconClicked();

    void onItemClicked(QTreeWidgetItem *item, int column);
    void onItemExpanded(QTreeWidgetItem *item);
    void onItemCollapsed(QTreeWidgetItem *item);
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CCMainWindow *ui;
    SysTray *tray;         // 系统托盘
    bool m_isAccountLogin; // 是否为账号登录
    QString m_account;     // 登录的账号或员工号
};
#endif // CCMAINWINDOW_H
