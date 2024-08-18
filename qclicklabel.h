#ifndef QCLICKLABEL_H
#define QCLICKLABEL_H

#include <QLabel>

// 自定义可点击标签
class QClickLabel : public QLabel {
    Q_OBJECT
public:
    QClickLabel(QWidget *parent = nullptr);
    ~QClickLabel();

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();
};

#endif // QCLICKLABEL_H
