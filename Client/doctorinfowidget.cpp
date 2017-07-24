#include "doctorinfowidget.h"
#include "ui_doctorinfowidget.h"
extern ChatClient * cc;
DoctorInfoWidget::DoctorInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorInfoWidget)
{
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getRecord(QJsonArray)));
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    cc->sendSql("Select *from doctor;",ChatClient::QUE);
    cc->sendSql("insert into doctor(name,password) values('Tom','q1234');",ChatClient::EXC);
}

DoctorInfoWidget::~DoctorInfoWidget()
{

    delete ui;
}

void DoctorInfoWidget::getRecord(QJsonArray arr)
{
    qDebug() << arr.at(0).toObject().take("name").toString();
}

void DoctorInfoWidget::on_pushButton_clicked()
{

}
