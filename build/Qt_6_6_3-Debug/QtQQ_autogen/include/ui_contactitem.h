/********************************************************************************
** Form generated from reading UI file 'contactitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTITEM_H
#define UI_CONTACTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *userName;
    QLabel *signName;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ContactItem)
    {
        if (ContactItem->objectName().isEmpty())
            ContactItem->setObjectName("ContactItem");
        ContactItem->resize(483, 54);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ContactItem->sizePolicy().hasHeightForWidth());
        ContactItem->setSizePolicy(sizePolicy);
        ContactItem->setMinimumSize(QSize(0, 54));
        ContactItem->setMaximumSize(QSize(16777215, 54));
        horizontalLayout = new QHBoxLayout(ContactItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 0, 6, 0);
        label = new QLabel(ContactItem);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(78, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        userName = new QLabel(ContactItem);
        userName->setObjectName("userName");

        verticalLayout->addWidget(userName);

        signName = new QLabel(ContactItem);
        signName->setObjectName("signName");

        verticalLayout->addWidget(signName);

        verticalSpacer_2 = new QSpacerItem(78, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ContactItem);

        QMetaObject::connectSlotsByName(ContactItem);
    } // setupUi

    void retranslateUi(QWidget *ContactItem)
    {
        ContactItem->setWindowTitle(QCoreApplication::translate("ContactItem", "Form", nullptr));
        label->setText(QString());
        userName->setText(QString());
        signName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactItem: public Ui_ContactItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTITEM_H
