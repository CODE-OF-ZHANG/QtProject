#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 添加默认选项
    ui->radioButton_male->setChecked(true);
    // 更新文本内容
    ui->label->setText("您选择的性别是: 男");
    // 禁用 其他 选项
    // checkable 只能够让按钮不被选中, 但仍然可以触发点击时间
    // ui->radioButton_other->setChecked(false);
    ui->radioButton_other->setEnabled(false);
    // ui->radioButton_other->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_male_clicked()
{
   // 点击之后更新文本内容
    ui->label->setText("您选择的性别是: 男");
}

void Widget::on_radioButton_female_clicked()
{
   // 点击之后更新文本内容
    ui->label->setText("您选择的性别是: 女");
}

void Widget::on_radioButton_other_clicked()
{
   // 点击之后更新文本内容
    ui->label->setText("您选择的性别是: 其他");
}
