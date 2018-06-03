#include "securityinfoview.h"
#include "ui_securityinfoview.h"

SecurityInfoView::SecurityInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecurityInfoView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
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

void SecurityInfoView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    ui->label_2->setText(resultSet.at(0)->take("username").toString());
}

void SecurityInfoView::on_backButton_clicked()
{
    this->close();
}
