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
    // 将控件设置成禁用状态
    button->setEnabled(false);

    connect(button, &QPushButton::clicked, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    qDebug() << "handle";
}

