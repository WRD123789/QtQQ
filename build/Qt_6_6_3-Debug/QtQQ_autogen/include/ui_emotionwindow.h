/********************************************************************************
** Form generated from reading UI file 'emotionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONWINDOW_H
#define UI_EMOTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmotionWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *topWidget;
    QWidget *bottomWidget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *emotionWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;

    void setupUi(QWidget *EmotionWindow)
    {
        if (EmotionWindow->objectName().isEmpty())
            EmotionWindow->setObjectName("EmotionWindow");
        EmotionWindow->resize(480, 358);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmotionWindow->sizePolicy().hasHeightForWidth());
        EmotionWindow->setSizePolicy(sizePolicy);
        EmotionWindow->setMinimumSize(QSize(480, 358));
        EmotionWindow->setMaximumSize(QSize(480, 358));
        verticalLayout_3 = new QVBoxLayout(EmotionWindow);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName("verticalLayout_3");
        topWidget = new QWidget(EmotionWindow);
        topWidget->setObjectName("topWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topWidget->sizePolicy().hasHeightForWidth());
        topWidget->setSizePolicy(sizePolicy1);
        topWidget->setMinimumSize(QSize(0, 62));
        topWidget->setMaximumSize(QSize(16777215, 62));

        verticalLayout_3->addWidget(topWidget);

        bottomWidget = new QWidget(EmotionWindow);
        bottomWidget->setObjectName("bottomWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bottomWidget->sizePolicy().hasHeightForWidth());
        bottomWidget->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(bottomWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(bottomWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        emotionWidget = new QWidget();
        emotionWidget->setObjectName("emotionWidget");
        emotionWidget->setGeometry(QRect(0, 0, 456, 260));
        sizePolicy2.setHeightForWidth(emotionWidget->sizePolicy().hasHeightForWidth());
        emotionWidget->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(emotionWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");

        verticalLayout->addLayout(gridLayout);

        scrollArea->setWidget(emotionWidget);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_3->addWidget(bottomWidget);


        retranslateUi(EmotionWindow);

        QMetaObject::connectSlotsByName(EmotionWindow);
    } // setupUi

    void retranslateUi(QWidget *EmotionWindow)
    {
        EmotionWindow->setWindowTitle(QCoreApplication::translate("EmotionWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmotionWindow: public Ui_EmotionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONWINDOW_H
