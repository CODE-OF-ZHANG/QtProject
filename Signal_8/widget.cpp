#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    this->setWindowTitle("修改标题");
}

void Widget::handleClick2()
{
    // 绑定新的槽函数
    this->setWindowTitle("修改标题2");
}


void Widget::on_pushButton_2_clicked()
{
    // 断开pushbutton原来的信号槽
    disconnect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
    // 绑定新的槽函数
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick2);
}
