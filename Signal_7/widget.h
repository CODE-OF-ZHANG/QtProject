#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

signals:
    void MySignal_1();
    void MySignal_2();
    void MySignal_3();

public slots:
    void slots_1();
    void slots_2();
    void slots_3();
};
#endif // WIDGET_H
