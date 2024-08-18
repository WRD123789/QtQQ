#include "talkwindowshell.h"
#include "./ui_talkwindowshell.h"
#include "commonutils.h"

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
