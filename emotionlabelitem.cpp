#include "emotionlabelitem.h"

#include <QMovie>

EmotionLabelItem::EmotionLabelItem(QWidget *parent)
    : QClickLabel{parent}
{
    initControl();

    connect(this, &QClickLabel::clicked, [this] {
        emit emotionClicked(m_emotionNum);
    });
}

EmotionLabelItem::~EmotionLabelItem()
{}

void EmotionLabelItem::setEmotionMovie(int emotionNum)
{
    m_emotionNum = emotionNum;

    QString imagePath = QString(":/Resources/MainWindow/emotion/%1.png").arg(emotionNum);
    m_apngMovie = new QMovie(imagePath, "apng", this);
    //m_apngMovie->start();
    //m_apngMovie->stop();
    setMovie(m_apngMovie);
}

void EmotionLabelItem::initControl()
{
    setAlignment(Qt::AlignCenter);
    setObjectName("emotionLabelItem");
    setFixedSize(32, 32);
}
