#include "widget.h"
#include "ui_widget.h"
#include <chatclient.h>
extern ChatClient * cc;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    cc->sendSql("Select * from doctor;",ChatClient::QUE);
}
