#ifndef EMOTIONWINDOW_H
#define EMOTIONWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class EmotionWindow;
}
QT_END_NAMESPACE

// 表情窗口
class EmotionWindow : public QWidget {
    Q_OBJECT
public:
    EmotionWindow(QWidget *parent = nullptr);
    ~EmotionWindow();

private:
    void initControl();

private slots:
    void addEmotion(int emotionNum); // 将表情添加到输入框中

signals:
    void signalEmotionWindowHide();
    void signalEmotionItemClicked(int emotionNum);

private:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::EmotionWindow *ui;
};

#endif // EMOTIONWINDOW_H
