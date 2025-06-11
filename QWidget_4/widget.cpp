#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    // 设置随机种子,
    srand(time(0));
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("快点叫爸爸！！");
}

void Widget::on_pushButton_rejected_clicked()
{
//    // 获取当前程序窗口尺寸
//    int width = this->geometry().width();
//    int height = this->geometry().height();
//    // 重新生成按钮位置
//    int x = rand() % width;
//    int y = rand() % height;
//    // 移动按钮的位置
//    ui->pushButton_rejected->move(x, y);
}

void Widget::on_pushButton_rejected_pressed()
{
    // 获取当前程序窗口尺寸
    int width = this->geometry().width();
    int height = this->geometry().height();
    // 重新生成按钮位置
    int x = rand() % width;
    int y = rand() % height;
    // 移动按钮的位置
    ui->pushButton_rejected->move(x, y);
}
