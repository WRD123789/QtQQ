#include "talkwindowshell.h"
#include "./ui_talkwindowshell.h"
#include "commonutils.h"
#include "talkwindow.h"

TalkWindowShell::TalkWindowShell(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::TalkWindowClass)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    initControl();
}

TalkWindowShell::~TalkWindowShell()
{
    delete m_emotionWindow;
    m_emotionWindow = nullptr;
}

void TalkWindowShell::addTalkWindow(TalkWindow *talkWindow, TalkWindowItem *talkWindowItem, GroupType groupType)
{
    ui->rightStackedWidget->addWidget(talkWindow);

    connect(m_emotionWindow, &EmotionWindow::signalEmotionWindowHide,
            talkWindow, &TalkWindow::onSetEmotionBtnStatus);

    // 关联左侧的列表项与聊天窗口
    QListWidgetItem *aItem = new QListWidgetItem(ui->listWidget);
    m_talkWindowItemMap.insert(aItem, talkWindow);

    aItem->setSelected(true);
}

void TalkWindowShell::setCurrentWidget(QWidget *widget)
{
    ui->rightStackedWidget->setCurrentWidget(widget);
}

void TalkWindowShell::initControl()
{
    loadStyleSheet("TalkWindow");
    setWindowTitle(QString::fromLocal8Bit("聊天窗口"));

    m_emotionWindow = new EmotionWindow;
    m_emotionWindow->hide();

    // 分类器进行尺寸划分
    QList<int> sizeList;
    sizeList << 154 << width() - 154;
    ui->splitter->setSizes(sizeList);

    ui->listWidget->setStyle(new CustomProxyStyle(this));

    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &TalkWindowShell::onTalkWindowItemClicked);
}

void TalkWindowShell::onEmotionBtnClicked(bool)
{
    m_emotionWindow->setVisible(!m_emotionWindow->isVisible());

    // 移动表情窗口到合适的位置
    QPoint emotionPoint = this->mapToGlobal(QPoint(0, 0)); // 获取当前窗口左上角相对于整个屏幕的位置 (局部坐标转换为全局坐标)
    emotionPoint.setX(emotionPoint.x() + 170);
    emotionPoint.setY(emotionPoint.y() + 220);
    m_emotionWindow->move(emotionPoint);
}

void TalkWindowShell::onTalkWindowItemClicked(QListWidgetItem *item)
{
    QWidget *talkWindow = m_talkWindowItemMap.value(item);
    ui->rightStackedWidget->setCurrentWidget(talkWindow);
}

void TalkWindowShell::onEmotionItemClicked(int emotionNum)
{
    TalkWindow *curTalkWindow = dynamic_cast<TalkWindow*>(ui->rightStackedWidget->currentWidget());
    if (curTalkWindow)
        curTalkWindow->addEmotionImage(emotionNum);
}
