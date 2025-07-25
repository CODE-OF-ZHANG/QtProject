#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

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


void Widget::on_pushButton_up_clicked()
{
    // 获取target的geometry
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.y() - 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    // 获取target的geometry
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.y() + 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    // 获取target的geometry
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.x() - 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    // 获取target的geometry
    QRect rect = ui->pushButton_target->geometry();
    qDebug() << rect;
//    rect.setY(rect.x() + 5);
//    ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}
