#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置按钮图标
    ui->pushButton_up->setIcon(QIcon(":/images/up.png"));
    ui->pushButton_up->setIconSize(QSize(100, 100));

    ui->pushButton_down->setIcon(QIcon(":/images/down.png"));
    ui->pushButton_down->setIconSize(QSize(100, 100));

    ui->pushButton_left->setIcon(QIcon(":/images/left.png"));
    ui->pushButton_left->setIconSize(QSize(100, 100));

    ui->pushButton_right->setIcon(QIcon(":/images/right.png"));
    ui->pushButton_right->setIconSize(QSize(100, 100));

    ui->pushButton_target->setIcon(QIcon(":/images/preview.jpg"));
    ui->pushButton_target->setIconSize(QSize(120, 120));

    // 1. 直接通过键盘按键名称来设置快捷键
//    ui->pushButton_up->setShortcut(QKeySequence("w"));
//    ui->pushButton_down->setShortcut(QKeySequence("s"));
//    ui->pushButton_left->setShortcut(QKeySequence("a"));
//    ui->pushButton_right->setShortcut(QKeySequence("d"));

    // 2. 通过按键枚举设置快捷键
    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));

    // 开启鼠标点击的连发功能 (键盘默认可以连发)
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    // 获取到 target 的位置
    QRect rect = ui->pushButton_target->geometry();
    // 基于上次的位置, 设置新的位置
    ui->pushButton_target->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    // 获取到 target 的位置
    QRect rect = ui->pushButton_target->geometry();
    // 基于上次的位置, 设置新的位置
    ui->pushButton_target->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    // 获取到 target 的位置
    QRect rect = ui->pushButton_target->geometry();
    // 基于上次的位置, 设置新的位置
    ui->pushButton_target->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    // 获取到 target 的位置
    QRect rect = ui->pushButton_target->geometry();
    // 基于上次的位置, 设置新的位置
    ui->pushButton_target->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}
