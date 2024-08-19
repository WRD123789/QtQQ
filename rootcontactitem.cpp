#include "rootcontactitem.h"

#include <QPainter>

RootContactItem::RootContactItem(bool hasArrow, QWidget *parent)
    : QLabel{parent}
    , m_rotation(0)
    , m_hasArrow(hasArrow)
{
    setFixedHeight(32);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // 初始化属性动画
    m_animation = new QPropertyAnimation(this, "rotation");
    m_animation->setDuration(50);                      // 设置单次动画时长
    m_animation->setEasingCurve(QEasingCurve::InQuad); // 设置动画缓和曲线类型
}

RootContactItem::~RootContactItem()
{}

void RootContactItem::setText(const QString &title)
{
    m_titleText = title;

    update(); // 界面重绘
}

void RootContactItem::setExpanded(bool expand)
{
    // 设置动画结束时目标属性的目标值, 即箭头角度
    if (expand)
        m_animation->setEndValue(90);
    else
        m_animation->setEndValue(0);

    // 启动动画
    m_animation->start();
}

int RootContactItem::rotation()
{
    return m_rotation;
}

void RootContactItem::setRotation(int rotation)
{
    m_rotation = rotation;

    update(); // 界面重绘
}

void RootContactItem::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing, true); // 文本反锯齿

    QFont font;
    font.setPointSize(10);

    // 将文本绘制到组件上
    painter.setFont(font);
    painter.drawText(24, 0, width() - 24, height(), Qt::AlignLeft | Qt::AlignVCenter, m_titleText);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.save();

    if (m_hasArrow) {
        QPixmap pix;
        pix.load(":/Resources/MainWindow/arrow.png");

        QPixmap tmpPix(pix.size());
        tmpPix.fill(Qt::transparent);

        QPainter p(&tmpPix);
        p.setRenderHint(QPainter::SmoothPixmapTransform, true);

        // 绘制一个旋转后的图片
        p.translate(pix.width() / 2, pix.height() / 2);
        p.rotate(m_rotation);
        p.drawPixmap(0 - pix.width() / 2, 0 - pix.height() / 2, pix);

        // 将图片绘制到组件上
        painter.drawPixmap(6, (height() - pix.height()) / 2, tmpPix);
    }

    painter.restore(); // 恢复

    QLabel::paintEvent(event);
}


