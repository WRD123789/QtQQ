#include "msgwebview.h"

#include <QFile>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWebChannel>

MsgHtmlObj::MsgHtmlObj(QObject *parent)
    : QObject{parent}
{
    initHtmlTmpl();
}

void MsgHtmlObj::initHtmlTmpl()
{
    m_msgLHtmlTmpl = getMsgTmplHtml("msgleftTmpl");
    m_msgRHtmlTmpl = getMsgTmplHtml("msgrightTmpl");
}

QString MsgHtmlObj::getMsgTmplHtml(const QString &code)
{
    QFile file(QString(":/Resources/MainWindow/MsgHtml/%1.html").arg(code));
    file.open(QFile::ReadOnly);

    QString data;
    if (file.isOpen()) {
        data = QLatin1String(file.readAll());
    } else {
        QMessageBox::information(nullptr, "Tips", "Failed to init html!");

        return QString("");
    }

    file.close();

    return data;
}

bool MsgWebPage::acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame)
{
    // 仅接收 qrc:/*.html
    if (url.scheme() == QString("qrc"))
        return true;

    return false;
}

MsgWebView::MsgWebView(QWidget *parent)
    : QWebEngineView{parent}
{
    // 将 `page` 设置为当前 `QWebEngineView` 的页面对象
    // 此时 `QWebEngineView` 就会使用 `MsgWebPage` 类来渲染和处理网页
    MsgWebPage *page = new MsgWebPage(this);
    setPage(page);

    // `QWebChannel` 用于在 Qt 应用程序和网页之间建立通信通道
    QWebChannel *channel = new QWebChannel(this);
    m_msgHtmlObj = new MsgHtmlObj(this);
    // 将 `m_msgHtmlObj` 注册到 `QWebChannel` 中
    // 此时, 网页中的 JavaScript 代码就可以通过 external 这个标识符访问到 `m_msgHtmlObj` 对象
    channel->registerObject("external", m_msgHtmlObj);
    this->page()->setWebChannel(channel);

    // 初始化消息页面
    this->load(QUrl("qrc:/Resources/MainWindow/MsgHtml/msgTmpl.html"));
}

MsgWebView::~MsgWebView()
{}

void MsgWebView::appendMsg(const QString &htmlMsg)
{
    QJsonObject msgObj;
    QString msg;
    const QList<QStringList> msgList = parseHtml(htmlMsg);

    for (int i = 0; i < msgList.length(); i += 1) {
        if (msgList.at(i).at(0) == "img") {
            QString imagePath = msgList.at(i).at(1);
            QPixmap pix;
            // 根据图片路径中有无 qrc 来处理
            if (imagePath.left(3) == "qrc")
                pix.load(imagePath.mid(3));
            else
                pix.load(imagePath);

            // 生成表情图片 HTML 格式文本
            QString imageMsg = QString("<img src=\"%1\" width=\"%2\" height=\"%3\"/>")
                               .arg(imagePath).arg(pix.width()).arg(pix.height());
            msg += imageMsg;
        } else if (msgList.at(i).at(0) == "text") {
            msg += msgList.at(i).at(1);
        }
    }

    msgObj.insert("MSG", msg);

    const QString &resMsg = QJsonDocument(msgObj).toJson(QJsonDocument::Compact);
    this->page()->runJavaScript(QString("appendHtml(%1)").arg(resMsg));
}

QList<QStringList> MsgWebView::parseHtml(const QString &htmlMsg)
{
    // 获取 HTML 消息中的第一个 `<body>` 节点并解析它
    QDomDocument doc;
    doc.setContent(htmlMsg);
    const QDomElement &root = doc.documentElement();
    const QDomNode &node = root.firstChildElement("body");

    return parseDocNode(node);
}

QList<QStringList> MsgWebView::parseDocNode(const QDomNode &node)
{
    QList<QStringList> attribute;
    const QDomNodeList &list = node.childNodes();

    for (int i = 0; i < list.length(); i += 1) {
        const QDomNode &node = list.at(i);

        if (node.isElement()) {
            const QDomElement &element = node.toElement();

            if (element.tagName() == "img") {
                QStringList attributeList;
                attributeList << "img" << element.attribute("src");
                attribute << attributeList;
            }

            if (element.tagName() == "p") {
                QStringList attributeList;
                attributeList << "text" << element.text();
                attribute << attributeList;
            }

            if (element.hasChildNodes())
                attribute << parseDocNode(node);
        }
    }

    return attribute;
}
