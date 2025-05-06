#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyLabel* label = new MyLabel(this);
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}

