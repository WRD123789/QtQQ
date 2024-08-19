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
    TalkWindow(QWidget *parent, const QString &windowID, GroupType groupType);
    ~TalkWindow();

public:
    void addEmotionImage(int emotionNum);
    void setWindowName(const QString &name);

public slots:
    void onSetEmotionBtnStatus();

private slots:
    void onSendBtnClicked();
    void onItemDoubleClicked(QTreeWidgetItem* item, int column);

private:
    void initControl();

    void initCompanyTalk();     // 初始化公司群聊天
    void initPersonelTalk();    // 初始化人事部聊天
    void initDevelopmentTalk(); // 初始化研发部聊天
    void initMarketTalk();      // 初始化市场部聊天
    void initPToPTalk();        // 初始化单人聊天

    void addPeopleInfo(QTreeWidgetItem *pRootGroupItem);

private:
    Ui::TalkWindow *ui;
    QString m_windowID;
    GroupType m_groupType;
    QMap<QTreeWidgetItem*, QString> m_groupPeopleMap; // 包含群组中所有人员的名字
};

#endif // TALKWINDOW_H
