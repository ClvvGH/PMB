#include "doctormainview.h"
#include "ui_doctormainview.h"

DoctorMainView::DoctorMainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorMainView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

DoctorMainView::~DoctorMainView()
{
    delete ui;
}

void DoctorMainView::on_pushButton_clicked()
{
    SelfInfoView *siv = new SelfInfoView();
    connect(siv,SIGNAL(logout()),this,SLOT(logout()));
    siv->show();
}

void DoctorMainView::logout()
{
    LoginView *lv =new LoginView();
    lv->show();
    this->close();
}

void DoctorMainView::on_pushButton_5_clicked()
{
    DoctorListView *dlv = new DoctorListView();
    dlv->show();
}

void DoctorMainView::on_pushButton_2_clicked()
{
    PatientListView *plv = new PatientListView();
    plv->show();
}

void DoctorMainView::on_pushButton_3_clicked()
{
    ChosePatientView *cpv = new  ChosePatientView();
    cpv->show();
}
