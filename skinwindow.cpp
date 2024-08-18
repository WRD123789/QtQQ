#include "skinwindow.h"
#include "./ui_skinwindow.h"
#include "qclicklabel.h"
#include "notifymanager.h"

SkinWindow::SkinWindow(QWidget *parent)
    : BasicWindow{parent}
    , ui(new Ui::SkinWindow)
{
    ui->setupUi(this);

    loadStyleSheet("SkinWindow");
    initControl();
}

SkinWindow::~SkinWindow()
{
    delete ui;
}

void SkinWindow::initControl()
{
    QList<QColor> colorList = {
        QColor(22, 154, 218), QColor(40, 138, 221), QColor(49, 166, 107),
        QColor(218, 67, 68), QColor(177, 99, 158), QColor(107, 81, 92),
        QColor(89, 92, 160), QColor(79, 169, 172), QColor(155, 183, 154),
        QColor(128, 77, 77), QColor(240, 188, 189), QColor(21, 156, 189)
    };

    for (int row = 0; row < 3; row += 1) {
        for (int column = 0; column < 4; column += 1) {
            QClickLabel *label = new QClickLabel(this);
            label->setCursor(Qt::PointingHandCursor);

            connect(label, &QClickLabel::clicked, [row, column, colorList] {
                NotifyManager::getInstance()->notifyOtherWindowChangeSkin(colorList.at(row * 4 + column));
            });

            label->setFixedSize(84, 84);

            // 设置标签颜色
            QPalette palette;
            palette.setColor(QPalette::Window, colorList.at(row * 4 + column));
            label->setAutoFillBackground(true);
            label->setPalette(palette);

            ui->gridLayout->addWidget(label, row, column);
        }
    }

    connect(ui->sysmin, &QPushButton::clicked, this, &BasicWindow::onShowMin);
    connect(ui->sysclose, &QPushButton::clicked, this, &BasicWindow::onShowClose);
}
