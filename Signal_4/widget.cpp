#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, &Widget::MySignal, this, &Widget::handleMySignal);

    // emit MySignal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal()
{
    this->setWindowTitle("处理自定义信号");
}


void Widget::on_pushButton_clicked()
{
    // 发送自定义信号
    // 发送信号的操作, 可以在任意合适的代码中, 不一定非得在构造函数里

    // 通过内置信号, 处理自定义信号
    emit MySignal();
}
