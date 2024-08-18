#ifndef TALKWINDOWSHELL_H
#define TALKWINDOWSHELL_H

#include "basicwindow.h"
#include "emotionwindow.h"
#include "talkwindowitem.h"

#include <QWidget>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class TalkWindowClass;
}
QT_END_NAMESPACE

enum GroupType {
    COMPANY = 0,      // 公司群
    PERSONELGROUP,    // 人事部
    DEVELOPMENTGROUP, // 研发部
    MARKETGROUP,      // 市场部
    PTOP              // 单独聊天
};

class TalkWindow;

// 对话窗口
class TalkWindowShell : public BasicWindow {
    Q_OBJECT
public:
    TalkWindowShell(QWidget *parent = nullptr);
    ~TalkWindowShell();

public:
    // 添加新的聊天窗口
    void addTalkWindow(TalkWindow *talkWindow, TalkWindowItem *talkWindowItem, GroupType groupType);

    // 设置当前聊天窗口
    void setCurrentWidget(QWidget *widget);

private:
    void initControl();

public slots:
    void onEmotionBtnClicked(bool); // 表情按钮被点击后执行

private slots:
    void onTalkWindowItemClicked(QListWidgetItem *item); // 左侧列表点击后执行
    void onEmotionItemClicked(int emotionNum);           // 表情被选中后执行

private:
    Ui::TalkWindowClass *ui;

    // 打开的聊天窗口
    QMap<QListWidgetItem*, QWidget*> m_talkWindowItemMap;
    // 表情窗口
    EmotionWindow *m_emotionWindow;
};

#endif // TALKWINDOWSHELL_H
