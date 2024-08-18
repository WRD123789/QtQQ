#ifndef BASICWINDOW_H
#define BASICWINDOW_H

#include "titlebar.h"

#include <QDialog>

// 基本窗口, 需要被其他窗口继承
class BasicWindow : public QDialog {
    Q_OBJECT
public:
    BasicWindow(QWidget *parent = nullptr);
    virtual ~BasicWindow();

public:
    // 加载样式表
    void loadStyleSheet(const QString &sheetName);

    // 获取圆形头像
    QPixmap getRoundImage(const QPixmap &src, QPixmap &mask, QSize maskSize = QSize(0, 0));

private:
    // 初始化背景
    void initBackGroundColor();

protected:
    // 绘制事件
    void paintEvent(QPaintEvent *event);

    // 鼠标相关事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    void initTitleBar(ButtonType buttonType = MIN_BUTTON);
    void setTitleBarTitle(const QString &title, const QString &icon = "");

public slots:
    void onShowClose(bool);
    void onShowMin(bool);
    void onShowHide(bool);
    void onShowNormal(bool);
    void onShowQuit(bool);
    void onSignalSkinChanged(const QColor &color);

    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    QPoint m_mousePoint;      // 鼠标的相对位置 (相对于当前窗口左上角的位置偏移量)
    bool m_mousePressed;      // 鼠标是否按下
    QColor m_colorBackGround; // 背景颜色
    QString m_styleName;      // 样式表文件名称
    TitleBar *_titleBar;      // 标题栏
};

#endif // BASICWINDOW_H
