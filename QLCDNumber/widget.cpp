#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置初始值
    ui->lcdNumber->display("10");
    // 创建一个 QTimer 对象实例
    timer = new QTimer(this);
    // 槽函数
    connect(timer, &QTimer::timeout, this,&Widget::handle);
    // 启动计时器
    timer->start(1000);
}

void Widget::handle()
{
    // 先获取 LCDNumber 中的数字
    int value = ui->lcdNumber->intValue();
    if (value <= 0)
    {
        // 到 0 停止计时
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);
}

Widget::~Widget()
{
    delete ui;
}

