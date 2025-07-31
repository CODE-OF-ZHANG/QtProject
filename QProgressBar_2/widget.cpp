#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::handle);
    timer->start(100);
}

void Widget::handle()
{
    int value = ui->progressBar->value();
    if (value >= 100)
    {
        timer->stop();
        return;
    }
    ui->progressBar->setValue(value + 1);
}

Widget::~Widget()
{
    delete ui;
}

