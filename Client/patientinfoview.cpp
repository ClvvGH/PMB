#include "patientinfoview.h"
#include "ui_patientinfoview.h"

PatientInfoView::PatientInfoView(int PId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientInfoView)
{
    ui->setupUi(this);
    this->PId = PId;
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    cc->sendSql("Select * from patient where PId = '"+QString("%1").arg(PId)+"';",ChatClient::QUE);
    ui->name->setEnabled(false);
    ui->sex->setEnabled(false);
    ui->tel->setEnabled(false);
    ui->age->setEnabled(false);
}

PatientInfoView::PatientInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientInfoView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

PatientInfoView::~PatientInfoView()
{
    delete ui;
}

void PatientInfoView::on_backButton_clicked()
{
    this->close();
}

void PatientInfoView::getResult(QJsonArray arr)
{
    disconnect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    if (arr.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("出错了，请重试");
    }
    else
    {
        this->name = arr.at(0).toObject().take("name").toString();
        ui->name->setText(arr.at(0).toObject().take("name").toString());
        ui->age->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-arr.at(0).toObject().take("bornYear").toInt()+1));
        ui->sex->setText(arr.at(0).toObject().take("sex").toString());
        ui->tel->setText(arr.at(0).toObject().take("tel").toString());
    }
}

void PatientInfoView::on_treat_clicked()
{
    TreatView *tv = new  TreatView(PId,name);
    tv->show();
}

void PatientInfoView::on_treatMentButton_clicked()
{
    TreatListView *tlv = new TreatListView(PId);
    tlv->show();
}
