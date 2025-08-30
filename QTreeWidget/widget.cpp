#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("动物");

    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0, "猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0, "狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0, "鸟");
    ui->treeWidget->addTopLevelItem(item3);

    // 添加子节点
    QTreeWidgetItem* item4 = new QTreeWidgetItem();
    item4->setText(0, "狸花猫");
    item1->addChild(item4);

    QTreeWidgetItem* item5 = new QTreeWidgetItem();
    item5->setText(0, "橘猫");
    item1->addChild(item5);


    QTreeWidgetItem* item6 = new QTreeWidgetItem();
    item6->setText(0, "三花猫");
    item1->addChild(item6);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertTopLevelItem_clicked()
{
    const QString& text = ui->lineEdit->text();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_insertItem_clicked()
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr)
        return ;

    const QString& text = ui->lineEdit->text();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    currentItem->addChild(item);
}

void Widget::on_pushButton_deleteItem_clicked()
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr)
        return ;
    QTreeWidgetItem* parent = currentItem->parent();
    if (parent == nullptr)
    {
        int index = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {
        parent->removeChild(currentItem);
    }
}
