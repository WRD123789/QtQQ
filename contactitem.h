#ifndef CONTACTITEM_H
#define CONTACTITEM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ContactItem;
}

// `QTreeWidget` 中每个子项的自定义组件
class ContactItem : public QWidget {
    Q_OBJECT
public:
    ContactItem(QWidget *parent = nullptr);
    ~ContactItem();

public:
    void setUserName(const QString &userName);
    void setSignName(const QString &signName);
    void setHeadPixmap(const QPixmap &pix);

    QString getUserName() const;
    QSize getHeadLabelSize() const;

private:
    void initControl();

private:
    Ui::ContactItem *ui;
};

#endif // CONTACTITEM_H
