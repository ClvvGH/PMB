#include "securityinfoview.h"
#include "ui_securityinfoview.h"

SecurityInfoView::SecurityInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecurityInfoView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    if (identity == 1)
    {
        cc->sendSql("select * from doctor where DId ='"+QString("%1").arg(ID) +"';",ChatClient::QUE);
    }
    else
    {
        cc->sendSql("Select * from patient where PId = '"+QString("%1").arg(ID)+"';",ChatClient::QUE);
    }
}

SecurityInfoView::~SecurityInfoView()
{
    delete ui;
}

void SecurityInfoView::on_pushButton_clicked()
{
    ChangePasswordView *cpv = new ChangePasswordView();
    cpv->show();
}

void SecurityInfoView::getResult(QJsonArray arr)
{
    disconnect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    ui->label_2->setText(arr.at(0).toObject().take("username").toString());
}

void SecurityInfoView::on_backButton_clicked()
{
    this->close();
}
