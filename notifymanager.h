#ifndef NOTIFYMANAGER_H
#define NOTIFYMANAGER_H

#include <QObject>

// 皮肤改变通知器
class NotifyManager : public QObject {
    Q_OBJECT
public:
    NotifyManager();
    ~NotifyManager();

signals:
    void signalSkinChanged(const QColor &color);

public:
    static NotifyManager* getInstance();

    // 通知其他窗口改变颜色
    void notifyOtherWindowChangeSkin(const QColor &color);

private:
    static NotifyManager *instance;
};

#endif // NOTIFYMANAGER_H
