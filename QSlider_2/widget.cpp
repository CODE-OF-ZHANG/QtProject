#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 使用快捷键
    QShortcut* Shortcut1 = new QShortcut(this);
    Shortcut1->setKey(QKeySequence("-"));

    QShortcut* Shortcut2 = new QShortcut(this);
    Shortcut2->setKey(QKeySequence("="));

    connect(Shortcut1, &QShortcut::activated, this, &Widget::SubValue);
    connect(Shortcut2, &QShortcut::activated, this, &Widget::AddValue);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText("当前值为: " + QString::number(value));
}

void Widget::SubValue()
{
    // 获取当前值
    int value = ui->horizontalSlider->value();
    if (value <= ui->horizontalSlider->minimum())
        return ;
    ui->horizontalSlider->setValue(value - 5);
}

void Widget::AddValue()
{
    // 获取当前值
    int value = ui->horizontalSlider->value();
    if (value >= ui->horizontalSlider->maximum())
        return ;
    ui->horizontalSlider->setValue(value + 5);
}
