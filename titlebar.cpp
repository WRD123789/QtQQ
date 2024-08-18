#include "titlebar.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QFile>

#define BUTTON_HEIGHT 27 // 按钮高度
#define BUTTON_WIDTH  27 // 按钮宽度
#define TITLE_HEIGHT  27 // 标题栏高度

TitleBar::TitleBar(QWidget *parent)
    : QWidget{parent}
    , m_isPressed(false)
    , m_buttonType(MIN_MAX_BUTTON)
{
    initControl();
    initConnections();
    loadStyleSheet("Title");
}

TitleBar::~TitleBar()
{}

void TitleBar::initControl()
{
    m_pIcon = new QLabel(this);
    m_pTitleContent = new QLabel(this);

    m_pButtonMin = new QPushButton(this);
    m_pButtonRestore = new QPushButton(this);
    m_pButtonMax = new QPushButton(this);
    m_pButtonClose = new QPushButton(this);

    // 按钮设置固定大小
    m_pButtonMin->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    m_pButtonMax->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    m_pButtonClose->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));

    // 设置对象名
    m_pTitleContent->setObjectName("TitleContent");
    m_pButtonMin->setObjectName("ButtonMin");
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonClose->setObjectName("ButtonClose");

    // 设置布局
    QHBoxLayout *myLayout = new QHBoxLayout(this);
    myLayout->addWidget(m_pIcon);
    myLayout->addWidget(m_pTitleContent);
    myLayout->addWidget(m_pButtonMin);
    myLayout->addWidget(m_pButtonRestore);
    myLayout->addWidget(m_pButtonMax);
    myLayout->addWidget(m_pButtonClose);

    myLayout->setContentsMargins(5, 0, 0, 0); // 设置布局上、下、左、右的边距
    myLayout->setSpacing(0);                  // 设置布局中组件的间距

    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // 设置标题栏内容的尺寸策略

    setFixedHeight(TITLE_HEIGHT);
    setWindowFlag(Qt::FramelessWindowHint); // 窗口无边框
}

// 初始化信号与槽的连接
void TitleBar::initConnections()
{
    connect(m_pButtonMin, &QPushButton::clicked, this, &TitleBar::onButtonMinClicked);
    connect(m_pButtonRestore, &QPushButton::clicked, this, &TitleBar::onButtonRestoreClicked);
    connect(m_pButtonMax, &QPushButton::clicked, this, &TitleBar::onButtonMaxClicked);
    connect(m_pButtonClose, &QPushButton::clicked, this, &TitleBar::onButtonCloseClicked);
}

// 设置标题栏图标
void TitleBar::setTitleIcon(const QString &filePath)
{
    QPixmap titleIcon(filePath);
    m_pIcon->setFixedSize(titleIcon.size());
    m_pIcon->setPixmap(titleIcon);
}

// 设置标题栏内容
void TitleBar::setTitleContent(const QString &titleContent)
{
    m_pTitleContent->setText(titleContent);
    m_titleContent = titleContent;
}

// 设置标题栏宽度
void TitleBar::setTitleWidth(int width)
{
    setFixedWidth(width);
}

// 设置标题栏按钮类型
void TitleBar::setButtonType(ButtonType buttonType)
{
    m_buttonType = buttonType;

    switch(buttonType) {
        case MIN_BUTTON:
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
            break;
        case MIN_MAX_BUTTON:
            m_pButtonRestore->setVisible(false);
            break;
        case ONLY_CLOSE_BUTTON:
            m_pButtonMin->setVisible(false);
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
            break;
        default:
            break;
    }
}

// 保存最大化前窗口的位置和大小
void TitleBar::saveRestoreInfo(const QPoint &point, const QSize &size)
{
    m_restorePos = point;
    m_restoreSize = size;
}

// 获取最大化前窗口的位置和大小
void TitleBar::getRestoreInfo(QPoint &point, QSize &size)
{
    point = m_restorePos;
    size = m_restoreSize;
}

// 绘制标题栏
void TitleBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);                         // 设置填充规则
    pathBack.addRoundedRect(QRect(0, 0, width(), height()), 3, 3); // 添加圆角矩形到绘图路径
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);  // 启用平滑像素转换渲染提示

    // 当窗口最大化或还原时, 窗口宽度改变, 标题栏随之改变
    if (width() != parentWidget()->width())
        setFixedWidth(parentWidget()->width());

    QWidget::paintEvent(event);
}

// 双击响应事件, 实现双击标题栏最大化或还原窗口
void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (m_buttonType == MIN_MAX_BUTTON) {
        if (m_pButtonMax->isVisible())
            onButtonMaxClicked();
        else
            onButtonRestoreClicked();
    }

    return QWidget::mouseDoubleClickEvent(event);
}

// 通过鼠标按下、移动、释放事件实现拖动标题栏来移动窗口的效果
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (m_buttonType == MIN_MAX_BUTTON) {
        // 在窗口最大化时禁止拖动窗口
        if (m_pButtonMax->isVisible()) {
            m_isPressed = true;
            m_startMovePos = event->globalPosition().toPoint();
        }
    } else {
        m_isPressed = true;
        m_startMovePos = event->globalPosition().toPoint();
    }

    return QWidget::mousePressEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed) {
        QPoint moveDistance = event->globalPosition().toPoint() - m_startMovePos;
        QPoint parentPos = parentWidget()->pos();
        parentWidget()->move(parentPos.x() + moveDistance.x(), parentPos.y() + moveDistance.y());

        m_startMovePos = event->globalPosition().toPoint();
    }

    return QWidget::mouseMoveEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;

    return QWidget::mouseReleaseEvent(event);
}

// 加载样式表
void TitleBar::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/Resources/QSS/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen()) {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
    }

    file.close();
}

void TitleBar::onButtonMinClicked()
{
    emit signalButtonMinClicked();
}

void TitleBar::onButtonRestoreClicked()
{
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(true);

    emit signalButtonRestoreClicked();
}

void TitleBar::onButtonMaxClicked()
{
    m_pButtonRestore->setVisible(true);
    m_pButtonMax->setVisible(false);

    emit signalButtonMaxClicked();
}

void TitleBar::onButtonCloseClicked()
{
    emit signalButtonCloseClicked();
}
