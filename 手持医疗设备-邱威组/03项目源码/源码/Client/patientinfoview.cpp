#include "patientinfoview.h"
#include "ui_patientinfoview.h"

PatientInfoView::PatientInfoView(int PId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientInfoView)
{
    ui->setupUi(this);
    this->PId = PId;
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
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

void PatientInfoView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    if (resultSet.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("出错了，请重试");
    }
    else
    {
        ui->name->setText(resultSet.at(0)->take("name").toString());
        this->name = ui->name->text();
        ui->age->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-resultSet.at(0)->take("bornYear").toString().toInt()+1));
        ui->sex->setText(resultSet.at(0)->take("sex").toString());
        ui->tel->setText(resultSet.at(0)->take("tel").toString());
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

void PatientInfoView::on_examinationButton_clicked()
{
    ExaminationInfoView *eiv = new ExaminationInfoView(PId);
    eiv->show();
}
