#include "talkwindowitem.h"
#include "./ui_talkwindowitem.h"
#include "commonutils.h"

TalkWindowItem::TalkWindowItem(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::TalkWindowItem)
{
    ui->setupUi(this);

    initControl();
}

TalkWindowItem::~TalkWindowItem()
{}

void TalkWindowItem::setHeadPixmap(const QString &headPath)
{
    QPixmap mask(":/Resources/MainWindow/head_mask.png");
    QPixmap pix(headPath);
    QPixmap headPix = CommonUtils::getRoundImage(pix, mask, ui->headLabel->size());
    ui->headLabel->setPixmap(headPix);
}

void TalkWindowItem::setMsgLabelContent(const QString &msg)
{
    ui->msgLabel->setText(msg);
}

QString TalkWindowItem::getMsgLabelText()
{
    return ui->msgLabel->text();
}

void TalkWindowItem::initControl()
{
    ui->tcloseBtn->setVisible(false);

    connect(ui->tcloseBtn, &QPushButton::clicked, this, &TalkWindowItem::signalCloseClicked);
}

void TalkWindowItem::enterEvent(QEnterEvent *event)
{
    ui->tcloseBtn->setVisible(true);

    QWidget::enterEvent(event);
}

void TalkWindowItem::leaveEvent(QEvent *event)
{
    ui->tcloseBtn->setVisible(false);

    QWidget::leaveEvent(event);
}

void TalkWindowItem::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}
