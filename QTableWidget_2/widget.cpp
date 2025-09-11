#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QWidget>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 初始化
    QLabel* label = new QLabel(ui->tab);
    label->setText("标签页 1");
    label->resize(100, 50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页 2");
    label2->resize(100, 50);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 获取标签的个数
    int count = ui->tabWidget->count();
    // 创建新的标签页
    QWidget* w = new QWidget();
    ui->tabWidget->addTab(w, QString("tab ") + QString::number(count + 1));
    // 添加 label 标签
    QLabel* label = new QLabel(w);
    label->setText(QString("标签页 ") + QString::number(count + 1));
    label->resize(100, 50);

    // 设置新的标签页被选中
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_2_clicked()
{
    // 获取选中标签页的下标
    int index = ui->tabWidget->currentIndex();
    // 删除标签页
    ui->tabWidget->removeTab(index);
}

void Widget::on_tabWidget_currentChanged(int index)
{
    qDebug() << "当前选中的标签页的 index 为: " << index;
}
