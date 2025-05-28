#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::MySignal, this, &Widget::handleMySignal);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal(const QString &text)
{
    this->setWindowTitle(text);
}


void Widget::on_pushButton_clicked()
{
    emit MySignal("设置文本1为标题", 110);
}

void Widget::on_pushButton_2_clicked()
{
    emit MySignal("设置文本2为标题", 100);
}
