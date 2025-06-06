#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(300, 300);

    // 为引用外部变量
//    connect(button, &QPushButton::clicked, this, [](){
//       qDebug() << "lambda被执行";
//    });

//    // 引用外部变量
//    connect(button, &QPushButton::clicked, this, [button](){
//       qDebug() << "lambda被执行";
//       button->move(100, 100);
//    });

//    // 引用外部变量
//    connect(button, &QPushButton::clicked, this, [button, this](){
//       qDebug() << "lambda被执行";
//       button->move(100, 100);
//       this->move(100, 100);
//    });

    // 引用外部变量
    connect(button, &QPushButton::clicked, this, [=](){
       qDebug() << "lambda被执行";
       button->move(100, 100);
       this->move(100, 100);
       this->setWindowTitle("lambda执行中");
    });
}

Widget::~Widget()
{
    delete ui;
}

