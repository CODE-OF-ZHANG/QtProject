#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, this, &Widget::handleClicked);
}

void Widget::handleClicked()
{
    // 按下按钮, 修改窗口标题
    this->setWindowTitle("按钮已经按下");
}

Widget::~Widget()
{
    delete ui;
}

