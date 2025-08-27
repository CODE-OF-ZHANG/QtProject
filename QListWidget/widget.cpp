#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Python");
    ui->listWidget->addItem("Java");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    ui->listWidget->addItem(text);
}

void Widget::on_pushButton_2_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row < 0)
        return ;
    ui->listWidget->takeItem(row);
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
   if (current != nullptr)
       qDebug() << "当前选中的元素: " << current->text();
   if (previous != nullptr)
       qDebug() << "当前选中的元素: " << previous->text();
}
