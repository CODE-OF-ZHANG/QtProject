#include "widget.h"
#include "ui_widget.h"
#include <fstream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 读取文件内容
    std::ifstream file("D:/User/zhangxu/config.txt");
    if (!file.is_open()) {
        qDebug() << "文件打开失败";
        return ;
    }

    // 按行来读取
    std::string line;
    while (std::getline(file, line)) {
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    // 关闭文件
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

