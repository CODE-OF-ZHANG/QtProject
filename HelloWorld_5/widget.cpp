#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

void Widget::handleClick()
{
    // 按钮被点击后, 按钮中的文本进行切换
    if(ui->pushButton->text() == QString("Hello World"))
    {
        ui->pushButton->setText("Hello Qt");
    }
    else
    {
        ui->pushButton->setText("Hello World");
    }
}

Widget::~Widget()
{
    delete ui;
}

