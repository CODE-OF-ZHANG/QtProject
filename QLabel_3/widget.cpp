#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("这是一段文本");
//    ui->label_2->setText("这是一段文本");
//    ui->label_3->setText("这是一段文本");
//    ui->label_4->setText("这是一段文本");

    // 设置对齐方式
    ui->label->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
//    ui->label_2->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
//    ui->label_3->setAlignment(Qt::AlignTop | Qt::AlignLeft);
//    ui->label_4->setAlignment(Qt::AlignRight | Qt::AlignRight);

    // 设置自动换行
    ui->label_2->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_2->setWordWrap(true);


    // 设置缩进
    ui->label_3->setText("这是一段很长的文本这是一段很长的文本这"
                         "是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);

    // 设置边距
    ui->label_4->setText("这是一段很长的文本这是一段很长的文本这"
                         "是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(50);
}

Widget::~Widget()
{
    delete ui;
}

