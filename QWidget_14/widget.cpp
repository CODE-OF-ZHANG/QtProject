#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_light_clicked()
{
    // 设置窗口样式
    this->setStyleSheet("background-color: white;");
    // 设置输入框样式
    ui->textEdit->setStyleSheet("background-color: white; color: black;");
    // 设置按钮样式
    ui->pushButton_light->setStyleSheet("color: black;");
    ui->pushButton_dark->setStyleSheet("color: black;");
}

void Widget::on_pushButton_dark_clicked()
{
    // 设置窗口样式
    this->setStyleSheet("background-color: black;");
    // 设置输入框样式
    ui->textEdit->setStyleSheet("background-color: black; color: white;");
    // 设置按钮样式
    ui->pushButton_light->setStyleSheet("color: white");
    ui->pushButton_dark->setStyleSheet("color: white");
}
