#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pixmap(":/preview.jpg");
    QCursor cursor(pixmap, 1, 1);
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

