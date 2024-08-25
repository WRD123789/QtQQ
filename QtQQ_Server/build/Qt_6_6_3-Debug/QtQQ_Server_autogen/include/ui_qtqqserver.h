/********************************************************************************
** Form generated from reading UI file 'qtqqserver.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTQQSERVER_H
#define UI_QTQQSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtQQServer
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidget;
    QWidget *widget;
    QLabel *imgLabel;
    QGroupBox *groupBox;
    QFrame *line;
    QComboBox *employeeDepBox;
    QLineEdit *nameLineEdit;
    QPushButton *selectPictureBtn;
    QPushButton *addBtn;
    QLabel *headLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget2;
    QFormLayout *formLayout;
    QComboBox *departmentBox;
    QPushButton *queryDepartmentBtn;
    QLineEdit *queryIDLineEdit;
    QPushButton *queryIDBtn;
    QLineEdit *logoutIDLineEdit;
    QPushButton *logoutBtn;

    void setupUi(QDialog *QtQQServer)
    {
        if (QtQQServer->objectName().isEmpty())
            QtQQServer->setObjectName("QtQQServer");
        QtQQServer->resize(999, 502);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtQQServer->sizePolicy().hasHeightForWidth());
        QtQQServer->setSizePolicy(sizePolicy);
        QtQQServer->setMinimumSize(QSize(999, 502));
        QtQQServer->setMaximumSize(QSize(999, 502));
        scrollArea = new QScrollArea(QtQQServer);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(1, 1, 700, 500));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(700, 500));
        scrollArea->setMaximumSize(QSize(700, 500));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 698, 498));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 700, 500));
        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(QtQQServer);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(702, 1, 296, 500));
        imgLabel = new QLabel(widget);
        imgLabel->setObjectName("imgLabel");
        imgLabel->setGeometry(QRect(0, 0, 301, 211));
        imgLabel->setTextFormat(Qt::AutoText);
        imgLabel->setPixmap(QPixmap(QString::fromUtf8("Resources/img/fly1.png")));
        imgLabel->setScaledContents(true);
        imgLabel->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 210, 291, 281));
        line = new QFrame(groupBox);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 170, 291, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        employeeDepBox = new QComboBox(groupBox);
        employeeDepBox->addItem(QString());
        employeeDepBox->addItem(QString());
        employeeDepBox->addItem(QString());
        employeeDepBox->setObjectName("employeeDepBox");
        employeeDepBox->setGeometry(QRect(170, 20, 113, 28));
        nameLineEdit = new QLineEdit(groupBox);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(160, 60, 113, 28));
        selectPictureBtn = new QPushButton(groupBox);
        selectPictureBtn->setObjectName("selectPictureBtn");
        selectPictureBtn->setGeometry(QRect(240, 100, 31, 32));
        sizePolicy.setHeightForWidth(selectPictureBtn->sizePolicy().hasHeightForWidth());
        selectPictureBtn->setSizePolicy(sizePolicy);
        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(170, 140, 113, 28));
        headLabel = new QLabel(groupBox);
        headLabel->setObjectName("headLabel");
        headLabel->setGeometry(QRect(170, 100, 41, 31));
        headLabel->setAlignment(Qt::AlignCenter);
        widget1 = new QWidget(groupBox);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(40, 10, 61, 131));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        widget2 = new QWidget(groupBox);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 190, 271, 91));
        formLayout = new QFormLayout(widget2);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 0, 0, 0);
        departmentBox = new QComboBox(widget2);
        departmentBox->addItem(QString());
        departmentBox->addItem(QString());
        departmentBox->addItem(QString());
        departmentBox->addItem(QString());
        departmentBox->setObjectName("departmentBox");

        formLayout->setWidget(0, QFormLayout::LabelRole, departmentBox);

        queryDepartmentBtn = new QPushButton(widget2);
        queryDepartmentBtn->setObjectName("queryDepartmentBtn");
        queryDepartmentBtn->setMinimumSize(QSize(113, 0));
        queryDepartmentBtn->setMaximumSize(QSize(113, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, queryDepartmentBtn);

        queryIDLineEdit = new QLineEdit(widget2);
        queryIDLineEdit->setObjectName("queryIDLineEdit");

        formLayout->setWidget(1, QFormLayout::LabelRole, queryIDLineEdit);

        queryIDBtn = new QPushButton(widget2);
        queryIDBtn->setObjectName("queryIDBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(queryIDBtn->sizePolicy().hasHeightForWidth());
        queryIDBtn->setSizePolicy(sizePolicy1);
        queryIDBtn->setMinimumSize(QSize(113, 29));
        queryIDBtn->setMaximumSize(QSize(113, 29));

        formLayout->setWidget(1, QFormLayout::FieldRole, queryIDBtn);

        logoutIDLineEdit = new QLineEdit(widget2);
        logoutIDLineEdit->setObjectName("logoutIDLineEdit");

        formLayout->setWidget(2, QFormLayout::LabelRole, logoutIDLineEdit);

        logoutBtn = new QPushButton(widget2);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setMinimumSize(QSize(113, 29));
        logoutBtn->setMaximumSize(QSize(113, 29));

        formLayout->setWidget(2, QFormLayout::FieldRole, logoutBtn);


        retranslateUi(QtQQServer);

        QMetaObject::connectSlotsByName(QtQQServer);
    } // setupUi

    void retranslateUi(QDialog *QtQQServer)
    {
        QtQQServer->setWindowTitle(QCoreApplication::translate("QtQQServer", "QtQQServer", nullptr));
        imgLabel->setText(QString());
        groupBox->setTitle(QString());
        employeeDepBox->setItemText(0, QCoreApplication::translate("QtQQServer", "\344\272\272\344\272\213\351\203\250", nullptr));
        employeeDepBox->setItemText(1, QCoreApplication::translate("QtQQServer", "\347\240\224\345\217\221\351\203\250", nullptr));
        employeeDepBox->setItemText(2, QCoreApplication::translate("QtQQServer", "\345\270\202\345\234\272\351\203\250", nullptr));

        nameLineEdit->setPlaceholderText(QCoreApplication::translate("QtQQServer", "\350\257\267\350\276\223\345\205\245\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
        selectPictureBtn->setText(QCoreApplication::translate("QtQQServer", "...", nullptr));
        addBtn->setText(QCoreApplication::translate("QtQQServer", "\346\226\260\345\242\236\345\221\230\345\267\245", nullptr));
        headLabel->setText(QCoreApplication::translate("QtQQServer", "\345\244\264\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("QtQQServer", "\345\221\230\345\267\245\351\203\250\351\227\250:", nullptr));
        label_3->setText(QCoreApplication::translate("QtQQServer", "\345\221\230\345\267\245\345\247\223\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("QtQQServer", "\345\221\230\345\267\245\345\244\264\345\203\217:", nullptr));
        departmentBox->setItemText(0, QCoreApplication::translate("QtQQServer", "\345\205\254\345\217\270\347\276\244", nullptr));
        departmentBox->setItemText(1, QCoreApplication::translate("QtQQServer", "\344\272\272\344\272\213\351\203\250", nullptr));
        departmentBox->setItemText(2, QCoreApplication::translate("QtQQServer", "\347\240\224\345\217\221\351\203\250", nullptr));
        departmentBox->setItemText(3, QCoreApplication::translate("QtQQServer", "\345\270\202\345\234\272\351\203\250", nullptr));

        queryDepartmentBtn->setText(QCoreApplication::translate("QtQQServer", "\346\237\245\350\257\242\345\221\230\345\267\245", nullptr));
        queryIDLineEdit->setPlaceholderText(QCoreApplication::translate("QtQQServer", "\350\257\267\350\276\223\345\205\245\345\221\230\345\267\245 ID", nullptr));
        queryIDBtn->setText(QCoreApplication::translate("QtQQServer", "\346\237\245\350\257\242\345\221\230\345\267\245", nullptr));
        logoutIDLineEdit->setPlaceholderText(QCoreApplication::translate("QtQQServer", "\350\257\267\350\276\223\345\205\245\345\221\230\345\267\245 ID", nullptr));
        logoutBtn->setText(QCoreApplication::translate("QtQQServer", "\346\263\250\351\224\200\345\221\230\345\267\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtQQServer: public Ui_QtQQServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTQQSERVER_H
