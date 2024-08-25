#ifndef QMSGTEXTEDIT_H
#define QMSGTEXTEDIT_H

#include <QTextEdit>
#include <QWidget>

class QMsgTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    QMsgTextEdit(QWidget *parent = nullptr);
    ~QMsgTextEdit();

private slots:
    void onEmotionImageFrameChange(int frame); // 动画改变时响应的槽函数

public:
    void addEmotionUrl(int emotionNum);
    void deleteAllEmotionImage(); // 清空文本框中的所有表情图片

private:
    QList<QString> m_listEmotionUrl;
    QMap<QMovie*, QString> m_emotionMap;
};

#endif // QMSGTEXTEDIT_H
