/********************************************************************************
** Form generated from reading UI file 'talkwindowitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKWINDOWITEM_H
#define UI_TALKWINDOWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TalkWindowItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *headLabel;
    QLabel *msgLabel;
    QPushButton *tcloseBtn;

    void setupUi(QWidget *TalkWindowItem)
    {
        if (TalkWindowItem->objectName().isEmpty())
            TalkWindowItem->setObjectName("TalkWindowItem");
        TalkWindowItem->resize(404, 42);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TalkWindowItem->sizePolicy().hasHeightForWidth());
        TalkWindowItem->setSizePolicy(sizePolicy);
        TalkWindowItem->setMinimumSize(QSize(0, 42));
        TalkWindowItem->setMaximumSize(QSize(16777215, 42));
        horizontalLayout = new QHBoxLayout(TalkWindowItem);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        headLabel = new QLabel(TalkWindowItem);
        headLabel->setObjectName("headLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(headLabel->sizePolicy().hasHeightForWidth());
        headLabel->setSizePolicy(sizePolicy1);
        headLabel->setMinimumSize(QSize(30, 30));
        headLabel->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(headLabel);

        msgLabel = new QLabel(TalkWindowItem);
        msgLabel->setObjectName("msgLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(msgLabel->sizePolicy().hasHeightForWidth());
        msgLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(msgLabel);

        tcloseBtn = new QPushButton(TalkWindowItem);
        tcloseBtn->setObjectName("tcloseBtn");
        sizePolicy1.setHeightForWidth(tcloseBtn->sizePolicy().hasHeightForWidth());
        tcloseBtn->setSizePolicy(sizePolicy1);
        tcloseBtn->setMinimumSize(QSize(16, 16));
        tcloseBtn->setMaximumSize(QSize(16, 16));
        tcloseBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(tcloseBtn);


        retranslateUi(TalkWindowItem);

        QMetaObject::connectSlotsByName(TalkWindowItem);
    } // setupUi

    void retranslateUi(QWidget *TalkWindowItem)
    {
        TalkWindowItem->setWindowTitle(QCoreApplication::translate("TalkWindowItem", "Form", nullptr));
        headLabel->setText(QString());
        msgLabel->setText(QString());
        tcloseBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TalkWindowItem: public Ui_TalkWindowItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKWINDOWITEM_H
