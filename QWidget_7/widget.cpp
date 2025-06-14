#include "widget.h"
#include "ui_widget.h"
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QIcon icon("D:/User/zhangxu/local/preview.jpg");
    // 使用qrc
    QIcon icon(":/preview.jpg");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

