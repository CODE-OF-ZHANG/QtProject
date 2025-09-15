#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建三个按钮, 添加到布局管理器当中
    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    QPushButton* button3 = new QPushButton("按钮3");

    // 布局管理器
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    // 将布局管理器添加到窗口之中
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

