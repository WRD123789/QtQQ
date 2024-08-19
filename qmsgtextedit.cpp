#include "qmsgtextedit.h"

#include <QMovie>
#include <QUrl>

QMsgTextEdit::QMsgTextEdit(QWidget *parent)
    : QTextEdit{parent}
{}

QMsgTextEdit::~QMsgTextEdit()
{
    deleteAllEmotionImage();
}

void QMsgTextEdit::onEmotionImageFrameChange(int frame)
{
    QMovie *movie = dynamic_cast<QMovie*>(sender());
    // 用 `movie` 中播放的新帧替换 `QTextDocument` 中与 `QUrl` 关联的图像资源
    // `QTextDocument`负责管理和存储富文本内容
    // `QTextLine` 负责显示 `QTextDocument` 中的内容
    // `QTextDocument` 中资源改变时, `QTextLine` 中显示内容随之改变
    document()->addResource(QTextDocument::ImageResource,
                            QUrl(m_emotionMap.value(movie)), movie->currentImage());

}

void QMsgTextEdit::addEmotionUrl(int emotionNum)
{
    const QString &imagePath = QString(":/Resources/MainWindow/emotion/%1.png")
                                   .arg(emotionNum);

    // 插入 HTML 格式的文本
    insertHtml(QString("<img src='%1' />").arg(imagePath));

    if (!m_listEmotionUrl.contains(imagePath)) {
        m_listEmotionUrl.append(imagePath);

        QMovie *apngMovie = new QMovie(imagePath, "apng", this);
        m_emotionMap.insert(apngMovie, imagePath);

        // 数据帧改变时发射信号
        connect(apngMovie, &QMovie::frameChanged,
                this, &QMsgTextEdit::onEmotionImageFrameChange);

        apngMovie->start();

        updateGeometry();
    }
}

void QMsgTextEdit::deleteAllEmotionImage()
{
    for (auto emotion = m_emotionMap.begin();
         emotion != m_emotionMap.end(); ++emotion)
        delete emotion.key();

    m_emotionMap.clear();
}
