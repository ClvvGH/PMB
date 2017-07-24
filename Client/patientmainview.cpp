#include "patientmainview.h"
#include "ui_patientmainview.h"

PatientMainView::PatientMainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientMainView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

}

PatientMainView::~PatientMainView()
{
    delete ui;
}


void PatientMainView::on_selfInfo_clicked()
{
    SelfInfoView *siv = new SelfInfoView();
    siv->show();
    connect(siv,SIGNAL(logout()),this,SLOT(logout()));
}



void PatientMainView::on_doctorlist_clicked()
{
     DoctorListView *dlv = new DoctorListView();
     dlv->show();
}


void PatientMainView::on_treatment_clicked()
{
    TreatListView *tlv = new TreatListView(ID);
    tlv->show();
}

void PatientMainView::logout()
{
    LoginView *lv =new LoginView();
    lv->show();
    this->close();
}
