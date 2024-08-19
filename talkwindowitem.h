#ifndef TALKWINDOWITEM_H
#define TALKWINDOWITEM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TalkWindowItem;
}
QT_END_NAMESPACE

class TalkWindowItem : public QWidget {
    Q_OBJECT
public:
    TalkWindowItem(QWidget *parent = nullptr);
    ~TalkWindowItem();

public:
    void setHeadPixmap(const QString &headPath);
    void setMsgLabelContent(const QString &msg);
    QString getMsgLabelText();

private:
    void initControl();

private:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void signalCloseClicked();

private:
    Ui::TalkWindowItem *ui;
};

#endif // TALKWINDOWITEM_H
