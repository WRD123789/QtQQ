#include "emotionwindow.h"
#include "./ui_emotionwindow.h"
#include "commonutils.h"
#include "emotionlabelitem.h"

#include <QPainter>
#include <QStyleOption>

const int emotionColumn = 14, emotionRow = 12;

EmotionWindow::EmotionWindow(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::EmotionWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint); // 无边框, 子窗口
    setAttribute(Qt::WA_TranslucentBackground);              // 透明背景
    setAttribute(Qt::WA_DeleteOnClose);                      // 窗口关闭时回收资源

    initControl();
}

EmotionWindow::~EmotionWindow()
{}

void EmotionWindow::initControl()
{
    CommonUtils::loadStyleSheet(this, "EmotionWindow");

    for (int row = 0; row < emotionRow; row += 1) {
        for (int column = 0; column < emotionColumn; column += 1) {
            EmotionLabelItem *item = new EmotionLabelItem(this);
            item->setEmotionMovie(row * emotionColumn + column);
            ui->gridLayout->addWidget(item, row, column);

            connect(item, &EmotionLabelItem::emotionClicked,
                    this, &EmotionWindow::addEmotion);
        }
    }
}

void EmotionWindow::addEmotion(int emotionNum)
{
    hide();

    emit signalEmotionWindowHide();
    emit signalEmotionItemClicked(emotionNum);
}

// 确保窗口有一个符合当前样式主题的背景
void EmotionWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter painter(this);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    QWidget::paintEvent(event);
}
