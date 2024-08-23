#ifndef TALKWINDOW_H
#define TALKWINDOW_H

#include "talkwindowshell.h"

#include <QWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class TalkWindow;
}
QT_END_NAMESPACE

class TalkWindow : public QWidget {
    Q_OBJECT
public:
    TalkWindow(QWidget *parent, const QString &windowID);
    ~TalkWindow();

public:
    void addEmotionImage(int emotionNum);
    void setWindowName(const QString &name);
    inline QString getWindowID() { return m_windowID; };

public slots:
    void onSetEmotionBtnStatus();

private slots:
    void onSendBtnClicked(bool);
    void onItemDoubleClicked(QTreeWidgetItem* item, int column);

private:
    void initControl();
    void initGroupTalkStatus();
    int getCompDepID();

    void initTalkWindow(); // 初始化群聊
    void initPToPTalk();   // 初始化单人聊天

    void addPeopleInfo(QTreeWidgetItem *pRootGroupItem, int employeeID);

private:
    Ui::TalkWindow *ui;
    QString m_windowID;
    bool m_isGroupTalk; // 是否为群聊
    QMap<QTreeWidgetItem*, QString> m_groupPeopleMap; // 包含群组中所有人员的名字
};

#endif // TALKWINDOW_H
