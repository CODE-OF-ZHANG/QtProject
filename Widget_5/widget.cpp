#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(100, 100);

//    // geometry 与 framegeometry 的区别
//    QRect rect1 = this->geometry();
//    QRect rect2 = this->frameGeometry();
//    qDebug() << rect1;
//    qDebug() << rect2;

    connect(button, &QPushButton::clicked, this, &Widget::handle);
}

void Widget::handle()
{
    // geometry 与 framegeometry 的区别
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

Widget::~Widget()
{
    delete ui;
}

