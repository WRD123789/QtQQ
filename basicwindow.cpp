#include "basicwindow.h"
#include "commonutils.h"
#include "notifymanager.h"

#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QApplication>
#include <QMouseEvent>
#include <QSqlQuery>

BasicWindow::BasicWindow(QWidget *parent)
    : QDialog(parent)
{
    m_colorBackGround = CommonUtils::getDefaultSkinColor();
    setWindowFlag(Qt::FramelessWindowHint);           // 窗体无边框
    setAttribute(Qt::WA_TranslucentBackground, true); // 窗体透明

    connect(NotifyManager::getInstance(), &NotifyManager::signalSkinChanged,
            this, &BasicWindow::onSignalSkinChanged);
}

BasicWindow::~BasicWindow()
{}

void BasicWindow::onSignalSkinChanged(const QColor &color)
{
    m_colorBackGround = color;
    loadStyleSheet(m_styleName);
}

void BasicWindow::setTitleBarTitle(const QString &title, const QString &icon)
{
    _titleBar->setTitleContent(title);
    _titleBar->setTitleIcon(icon);
}

void BasicWindow::initTitleBar(ButtonType buttonType)
{
    _titleBar = new TitleBar(this);
    _titleBar->setButtonType(buttonType);
    _titleBar->move(0, 0);

    connect(_titleBar, &TitleBar::signalButtonMinClicked, this, &BasicWindow::onButtonMinClicked);
    connect(_titleBar, &TitleBar::signalButtonRestoreClicked, this, &BasicWindow::onButtonRestoreClicked);
    connect(_titleBar, &TitleBar::signalButtonMaxClicked, this, &BasicWindow::onButtonMaxClicked);
    connect(_titleBar, &TitleBar::signalButtonCloseClicked, this, &BasicWindow::onButtonCloseClicked);
}

void BasicWindow::loadStyleSheet(const QString &sheetName)
{
    m_styleName = sheetName;

    QFile file(":/Resources/QSS/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen()) {
        QString qsstyleSheet = QLatin1String(file.readAll());

        // 获取用户当前皮肤的 RGB
        QString r = QString::number(m_colorBackGround.red());
        QString g = QString::number(m_colorBackGround.green());
        QString b = QString::number(m_colorBackGround.blue());

        qsstyleSheet += QString("QWidget[titleskin=true]\
                                {background-color:rgb(%1,%2,%3);\
                                border-top-left-radius:4px;}\
                                QWidget[bottomskin=true]\
                                {border-top:1px solid rgba(%1,%2,%3,100);\
                                background-color:rgba(%1,%2,%3,50);\
                                border-bottom-left-radius:4px;\
                                border-bottom-right-radius:4px;}").arg(r, g, b);
        setStyleSheet(qsstyleSheet);
    }

    file.close();
}

// 初始化窗口的基本背景颜色
void BasicWindow::initBackGroundColor()
{
    // `QStyleOption` 用于传递绘图选项, 包含关于绘制元素的信息
    // 用 `initFrom` 初始化 `QStyleOption` 对象时, 会使其包含目标窗口部件 (this) 的一些基本信息
    QStyleOption opt;
    opt.initFrom(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

// 子类化部件时, 需要重写绘图事件来设置背景
void BasicWindow::paintEvent(QPaintEvent *event)
{
    initBackGroundColor();

    QDialog::paintEvent(event);
}

// 将给定头像转换为圆头像
QPixmap BasicWindow::getRoundImage(const QPixmap &src, QPixmap &mask, QSize maskSize)
{
    // `mask` 是一个内容为空的圆形图片, 用于裁剪头像; `maskSize` 表示期望的圆头像的大小
    // 如果 `maskSize` 为 0, 则直接使用 `mask` 的大小
    if (maskSize == QSize(0, 0))
        maskSize = mask.size();
    else
        // 根据 `maskSize` 对 `mask` 进行缩放
        mask = mask.scaled(maskSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 保存转换后的图像
    QImage resultImage(maskSize, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&resultImage);

    // 将源图像 (`src`) 和遮罩图像 (`mask`) 结合起来
    painter.setCompositionMode(QPainter::CompositionMode_Source);     // 该组合模式下绘制的像素将完全替换目标图像的像素
    painter.fillRect(resultImage.rect(), Qt::transparent);            // 将整个 `resultImage` 填充为透明色
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver); // 该组合模式下新绘制的图像会叠加在现有内容之上
    painter.drawPixmap(0, 0, mask);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);   // 该组合模式下只有在源图像和目标图像都不透明的区域, 绘制的图像才会显示
    painter.drawPixmap(0, 0, src.scaled(maskSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    painter.end();

    return QPixmap::fromImage(resultImage);
}

void BasicWindow::onShowClose(bool)
{
    close();
}

void BasicWindow::onShowMin(bool)
{
    showMinimized();
}

void BasicWindow::onShowHide(bool)
{
    hide();
}

void BasicWindow::onShowNormal(bool)
{
    show();
    activateWindow();
}

void BasicWindow::onShowQuit(bool)
{
    QApplication::quit();
}

void BasicWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - m_mousePoint);

        event->accept();
    }
}

void BasicWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_mousePressed = true;
        m_mousePoint = event->globalPosition().toPoint() - pos();

        event->accept();
    }
}

void BasicWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
}

void BasicWindow::onButtonMinClicked()
{
    if (windowFlags() & Qt::Tool)
        hide();
    else
        showMinimized();
}

void BasicWindow::onButtonRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    _titleBar->getRestoreInfo(windowPos, windowSize);

    setGeometry(QRect(windowPos, windowSize));
}

void BasicWindow::onButtonMaxClicked()
{
    _titleBar->saveRestoreInfo(pos(), QSize(width(), height()));

    QRect desktopRect = QApplication::primaryScreen()->availableGeometry();
    QRect factRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3,
                           desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(factRect);
}

void BasicWindow::onButtonCloseClicked()
{
    close();
}
