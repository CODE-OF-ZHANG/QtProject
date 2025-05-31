#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, &Widget::MySignal_1, this, &Widget::slots_1);
    connect(this, &Widget::MySignal_2, this, &Widget::slots_1);
    connect(this, &Widget::MySignal_1, this, &Widget::slots_2);
    connect(this, &Widget::MySignal_2, this, &Widget::slots_3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slots_1()
{
    qDebug() << "MySlots_1";
}

void Widget::slots_2()
{
    qDebug() << "MySlots_2";
}

void Widget::slots_3()
{
    qDebug() << "MySlots_3";
}

