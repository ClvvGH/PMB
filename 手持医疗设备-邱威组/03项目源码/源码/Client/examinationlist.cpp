#include "examinationlist.h"
#include "ui_examinationlist.h"

examinationList::examinationList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::examinationList)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

examinationList::~examinationList()
{
    delete ui;
}

void examinationList::on_heartRate_pressed()
{
    ui->heartRate->setIconSize(QSize(40,40));
}

void examinationList::on_heartRate_released()
{
    ui->heartRate->setIconSize(QSize(60,60));
    Electrocardiograph *ecg = new Electrocardiograph();
    ecg->show();
}

void examinationList::on_backButton_released()
{
    this->close();
}

void examinationList::on_temperature_released()
{
    ChosePatientView *cpv = new ChosePatientView(1);
    cpv->show();
}
