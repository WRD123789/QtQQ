#ifndef SKINWINDOW_H
#define SKINWINDOW_H

#include "basicwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SkinWindow;
}
QT_END_NAMESPACE

// 皮肤窗口
class SkinWindow : public BasicWindow {
    Q_OBJECT
public:
    SkinWindow(QWidget *parent = nullptr);
    ~SkinWindow();

    void initControl();

private:
    Ui::SkinWindow *ui;
};

#endif // SKINWINDOW_H
