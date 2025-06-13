#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("设置窗口标题");
    // 按钮 -> 没有效果, 希望报错
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->setWindowTitle("按钮设置窗口标题");
}

Widget::~Widget()
{
    delete ui;
}

