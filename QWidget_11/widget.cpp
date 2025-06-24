#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* label = new QLabel(this);
    label->setText("这是一段文本");
    label->move(200, 200);

    // 创建字体对象
    QFont font;
    font.setFamily("仿宋");  // 设置字体
    font.setPixelSize(30);  // 设置字体大小
    font.setBold(true);  // 加粗
    font.setItalic(true);  // 斜体
    font.setUnderline(true);  // 下划线
    font.setStrikeOut(true);  // 删除线

    // 将 font 对象设置到 label 对象中
    label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}

