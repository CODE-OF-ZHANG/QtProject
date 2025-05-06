#include "mylabel.h"
#include <iostream>
#include <QDebug>

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{
    // 调用父类的构造函数, 加入对象树中
}

MyLabel::~MyLabel()
{
    // std::cout << "MyLabel 已销毁" << std::endl;
    qDebug() << "MyLabel 已销毁";
}
