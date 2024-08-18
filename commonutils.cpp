#include "commonutils.h"

#include <QImage>
#include <QPainter>
#include <QFile>
#include <QWidget>
#include <QApplication>
#include <QSettings>

CommonUtils::CommonUtils()
{}

QPixmap CommonUtils::getRoundImage(const QPixmap &src, QPixmap &mask, QSize maskSize)
{
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

void CommonUtils::loadStyleSheet(QWidget *widget, const QString &sheetName)
{
    QFile file(":/Resources/QSS/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen()) {
        QString qsstyleSheet = QLatin1String(file.readAll());
        widget->setStyleSheet(qsstyleSheet);
    }

    file.close();
}

void CommonUtils::setDefaultSkinColor(const QColor &color)
{
    const QString &&path = QApplication::applicationDirPath() + "/" + QString("tradeprintinfo.ini");
    QSettings settings(path, QSettings::IniFormat);
    settings.setValue("DefaultSkin/red", color.red());
    settings.setValue("DefaultSkin/green", color.green());
    settings.setValue("DefaultSkin/blue", color.blue());
}

QColor CommonUtils::getDefaultSkinColor()
{
    const QString &&path = QApplication::applicationDirPath() + "/" + QString("tradeprintinfo.ini");
    if (!QFile::exists(path))
        setDefaultSkinColor(QColor(22, 154, 218));

    QSettings settings(path, QSettings::IniFormat);
    QColor color;
    color.setRed(settings.value("DefaultSkin/red").toInt());
    color.setGreen(settings.value("DefaultSkin/green").toInt());
    color.setBlue(settings.value("DefaultSkin/blue").toInt());

    return color;
}
