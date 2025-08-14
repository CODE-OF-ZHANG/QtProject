#include "widget.h"
#include "ui_widget.h"
#include <QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 正则表达式验证
    QRegExp regExp("^1\\d{10}$");
    ui->lineEdit_phone->setValidator(new QRegExpValidator(regExp));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_phone_textEdited(const QString &text)
{
    QString content = text;
    int pos = 0;
    if (ui->lineEdit_phone->validator()->validate(content, pos) == QValidator::Acceptable) {
        // 验证通过
        ui->pushButton_submit->setEnabled(true);
    } else {
        // 验证不通过
        ui->pushButton_submit->setEnabled(false);
    }
}
