#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include <QProxyStyle>
#include <QPixmap>

// 改变默认的部件风格
class CustomProxyStyle : public QProxyStyle {
public:
    CustomProxyStyle(QObject *parent)
    {
        setParent(parent);
    }

    virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
        QPainter *painter, const QWidget *widget = 0)
    {
        if (PE_FrameFocusRect == element)
            // 去掉窗口中部件默认的边框或虚线框, 部件获取焦点时直接返回
            return;
        else
            QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

class CommonUtils {
public:
    CommonUtils();

public:
    static QPixmap getRoundImage(const QPixmap &src, QPixmap &mask, QSize maskSize = QSize(0, 0));
    static void loadStyleSheet(QWidget *widget, const QString &sheetName);
    static void setDefaultSkinColor(const QColor &color);
    static QColor getDefaultSkinColor();
};

#endif // COMMONUTILS_H
