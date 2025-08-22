#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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


void Widget::on_pushButton_clicked()
{
    // 获取时间
    QDateTime timeOld = ui->dateTimeEdit->dateTime();
    QDateTime timeNew = ui->dateTimeEdit_2->dateTime();

    // 计算时间差值
    //int days = timeOld.daysTo(timeNew);
    int seconds = timeOld.secsTo(timeNew);

    // 秒换算成小时
    int hours = (seconds / 3600) % 24;
    int days = (seconds / 3600) / 24;

    // 将结果放入 label 中
    ui->label->setText(QString("爱你已经持续了") + QString::number(days)
                       + QString("天零") + QString::number(hours)
                       + QString(" 小时！"));
}
