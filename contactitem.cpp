#include "contactitem.h"
#include "./ui_contactitem.h"

ContactItem::ContactItem(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::ContactItem)
{
    ui->setupUi(this);

    initControl();
}

ContactItem::~ContactItem()
{}

void ContactItem::setUserName(const QString &userName)
{
    ui->userName->setText(userName);
}

void ContactItem::setSignName(const QString &signName)
{
    ui->signName->setText(signName);
}

void ContactItem::setHeadPixmap(const QPixmap &pix)
{
    ui->label->setPixmap(pix);
}

QString ContactItem::getUserName() const
{
    return ui->userName->text();
}

QSize ContactItem::getHeadLabelSize() const
{
    return ui->label->size();
}

void ContactItem::initControl()
{

}
