#ifndef EMOTIONLABELITEM_H
#define EMOTIONLABELITEM_H

#include "qclicklabel.h"

#include <QWidget>

// 表情标签
class EmotionLabelItem : public QClickLabel
{
    Q_OBJECT
public:
    EmotionLabelItem(QWidget *parent);
    ~EmotionLabelItem();

public:
    void setEmotionMovie(int emotionNum);

private:
    void initControl();

signals:
    void emotionClicked(int emotionNum);

private:
    int m_emotionNum;
    QMovie *m_apngMovie; // 动图
};

#endif // EMOTIONLABELITEM_H
