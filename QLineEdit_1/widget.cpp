#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 初试化第一个输入框
    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);

    // 初始化去第二个输入框
    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password->setClearButtonEnabled(true);
    // 修改显示模式
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    // 初始化第三个输入框
    ui->lineEdit_phone->setPlaceholderText("请输入手机号码");
    ui->lineEdit_phone->setClearButtonEnabled(true);
    // 输入格式 --> 校验 0 代表数字
    ui->lineEdit_phone->setInputMask("00000000000");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_submit_clicked()
{
    QString gender = ui->radioButton_male->isChecked() ? "男" : "女";

    qDebug() << "姓名: " << ui->lineEdit_name->text()
             << "密码: " << ui->lineEdit_password->text()
             << "性别: " << gender
             << "电话号码" << ui->lineEdit_phone->text();
}
