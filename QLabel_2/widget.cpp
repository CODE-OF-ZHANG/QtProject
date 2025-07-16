#include "widget.h"
#include "ui_widget.h"
#include <QResizeEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 让QLabel填充完整个窗口
    QRect windowRect = this->geometry();
    ui->label->setGeometry(0, 0, windowRect.width(), windowRect.height());
    QPixmap pixmap(":/preview.jpg");
    ui->label->setPixmap(pixmap);
    // 启动自动拉伸
    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    ui->label->setGeometry(0, 0, event->size().width(), event->size().height());
}

