#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

enum ButtonType {
    MIN_BUTTON = 0,   // 最小化及关闭按钮
    MIN_MAX_BUTTON,   // 最小化、最大化及关闭按钮
    ONLY_CLOSE_BUTTON // 只有关闭按钮
};

// 自定义标题栏
class TitleBar : public QWidget {
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();

    void setTitleIcon(const QString &filePath);        // 设置标题栏图标
    void setTitleContent(const QString &titleContent); // 设置标题栏内容
    void setTitleWidth(int width);               // 设置标题栏宽度
    void setButtonType(ButtonType buttonType);   // 设置标题栏按钮类型

    // 保存、获取窗口最大化前的位置和大小
    void saveRestoreInfo(const QPoint &point, const QSize &size);
    void getRestoreInfo(QPoint &point, QSize &size);

private:
    // 绘图事件
    void paintEvent(QPaintEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event); // 鼠标双击事件
    void mousePressEvent(QMouseEvent *event);       // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event);        // 鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *event);     // 鼠标释放事件

    void initControl();                            // 初始化控件
    void initConnections();                        // 初始化信号和槽的连接
    void loadStyleSheet(const QString &sheetName); // 初始化样式表

signals:
    // 按钮发送的信号
    void signalButtonMinClicked();     // 最小化按钮
    void signalButtonRestoreClicked(); // 最大化还原按钮
    void signalButtonMaxClicked();     // 最大化按钮
    void signalButtonCloseClicked();   // 关闭按钮

private slots:
    // 响应按钮
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

private:
    QLabel *m_pIcon;         // 标题栏图标
    QLabel *m_pTitleContent; // 标题栏内容标签

    QPushButton *m_pButtonMin;     // 最小化按钮
    QPushButton *m_pButtonRestore; // 最大化还原按钮
    QPushButton *m_pButtonMax;     // 最大化按钮
    QPushButton *m_pButtonClose;   // 关闭按钮

    // 用于最大化还原 (保存窗口位置和大小)
    QPoint m_restorePos;
    QSize m_restoreSize;

    // 用于移动窗口
    bool m_isPressed;
    QPoint m_startMovePos;

    QString m_titleContent;  // 标题栏内容
    ButtonType m_buttonType; // 标题栏按钮类型
};

#endif // TITLEBAR_H
