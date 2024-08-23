#ifndef MSGWEBVIEW_H
#define MSGWEBVIEW_H

#include <QWebEngineView>
#include <QWidget>
#include <QDomNode>

// 网页信息对象, 管理聊天界面中的 HTML 模板信息
class MsgHtmlObj : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString msgLHtmlTmpl MEMBER m_msgLHtmlTmpl NOTIFY signalMsgHtml)
    Q_PROPERTY(QString msgRHtmlTmpl MEMBER m_msgRHtmlTmpl NOTIFY signalMsgHtml)
public:
    MsgHtmlObj(QObject * parent);

signals:
    void signalMsgHtml(const QString &html); // 通知外部组件有新的 HTML 消息需要显示

private:
    void initHtmlTmpl(); // 初始化聊天网页
    QString getMsgTmplHtml(const QString &code);

private:
    QString m_msgLHtmlTmpl; // 收到的信息
    QString m_msgRHtmlTmpl; // 发出的信息
};

// 控制网页的内容加载, 确保只加载来自 qrc 资源的 URL
class MsgWebPage : public QWebEnginePage {
    Q_OBJECT
public:
    MsgWebPage(QObject *parent = nullptr)
        : QWebEnginePage{parent}
    {}

protected:
    // 限制接收的请求, 只接收 qrc 资源里面的类型
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame);
};

// 网页信息视图, 用于显示网页内容 (用于消息框)
class MsgWebView : public QWebEngineView {
    Q_OBJECT
public:
    MsgWebView(QWidget *parent);
    ~MsgWebView();

public:
    void appendMsg(const QString &htmlMsg, QString strObj = "0"); // 添加新的 HTML 消息到视图中

signals:
    void signalSendMsg(QString &msg, int &msgType, QString file = "");

private:
    QList<QStringList> parseHtml(const QString &htmlMsg);  // 解析 HTML 格式消息
    QList<QStringList> parseDocNode(const QDomNode &node); // 解析 HTML 节点

    MsgHtmlObj *m_msgHtmlObj;
};

#endif // MSGWEBVIEW_H
