#ifndef MSGWEBVIEW_H
#define MSGWEBVIEW_H

#include <QWebEngineView>
#include <QWidget>
#include <QDomNode>

// 显示网页内容 (用于聊天框)
class MsgWebView : public QWebEngineView
{
    Q_OBJECT
public:
    MsgWebView(QWidget *parent);
    ~MsgWebView();

public:
    void appendMsg(const QString &htmlMsg);

private:
    QList<QStringList> parseHtml(const QString &htmlMsg);  // 解析 HTML 格式消息
    QList<QStringList> parseDocNode(const QDomNode &node); // 解析 HTML 节点
};

#endif // MSGWEBVIEW_H
