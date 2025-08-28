#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建 3 行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    // 创建 3 列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    // 设置水平方向的表头
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

    // 添加数据
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("18"));

    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("21"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertRow_clicked()
{
    int RowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(RowCount);
}

void Widget::on_pushButton_deleteRow_clicked()
{
    int CurRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(CurRow);
}

void Widget::on_pushButton_insertColumn_clicked()
{
    int ColCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(ColCount);

    const QString& text = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(ColCount, new QTableWidgetItem(text));
}

void Widget::on_pushButton_deleteColumn_clicked()
{
    int curCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(curCol);
}
