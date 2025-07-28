#include "widget.h"
#include "ui_widget.h"
#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::thread t([this](){
        int value = this->ui->lcdNumber->intValue();
        while (true) {
            if (value <= 0)
                break;
            value -= 1;
            ui->lcdNumber->display(value);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

