#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 纯代码的方式实现按钮
    myButton = new QPushButton(this);
    myButton->setText("Hello World");

    connect(myButton, &QPushButton::clicked, this, &Widget::handleClick);
}

void Widget::handleClick()
{
    if(myButton->text() == QString("Hello World")){
        myButton->setText("Hello Qt");
    } else {
        myButton->setText("Hello World");
    }
}

Widget::~Widget()
{
    delete ui;
}

