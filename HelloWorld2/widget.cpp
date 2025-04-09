#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // QLabel label
    QLabel * label = new QLabel(this);
    label->setText("Hello World");
}

Widget::~Widget()
{
    delete ui;
}

