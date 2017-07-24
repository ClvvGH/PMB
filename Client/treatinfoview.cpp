#include "treatinfoview.h"
#include "ui_treatinfoview.h"

TreatInfoView::TreatInfoView(int row,int PId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreatInfoView)
{
    this->row = row;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->stackedWidget->setCurrentIndex(0);
    ui->leftButton->setEnabled(false);
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    cc->sendSql("Select * from treatment  natural join doctor where PId = '" +QString("%1").arg(PId)+"';",ChatClient::QUE);
}

TreatInfoView::~TreatInfoView()
{
    delete ui;
}

void TreatInfoView::getResult(QJsonArray arr)
{
    ui->DId->setText(QString("%1").arg(arr.at(row).toObject().take("DId").toInt()));
    ui->doctorName->setText(arr.at(row).toObject().take("name").toString());
    ui->disease->setText(arr.at(row).toObject().take("diseaseName").toString());
    ui->date->setText(arr.at(row).toObject().take("date").toString());
    ui->advice->setPlainText(arr.at(row).toObject().take("advice").toString());
    ui->description->setPlainText(arr.at(row).toObject().take("description").toString());
    ui->prescription->setPlainText(arr.at(row).toObject().take("prescription").toString());
    ui->diagnose->setPlainText(arr.at(row).toObject().take("diagnose").toString());
}
void TreatInfoView::on_leftButton_clicked()
{
    int index = ui->stackedWidget->currentIndex()-1;
    ui->stackedWidget->setCurrentIndex(index);
    if ( index == 0)
    {
        ui->leftButton->setEnabled(false);
    }
    else if (index == 3)
    {
        ui->rightButton->setEnabled(false);
    }
    else
    {
        ui->leftButton->setEnabled(true);
        ui->rightButton->setEnabled(true);
    }
}

void TreatInfoView::on_rightButton_clicked()
{
    int index = ui->stackedWidget->currentIndex()+1;
    ui->stackedWidget->setCurrentIndex(index);
    if ( index == 0)
    {
        ui->leftButton->setEnabled(false);
    }
    else if (index == 3)
    {
        ui->rightButton->setEnabled(false);
    }
    else
    {
        ui->leftButton->setEnabled(true);
        ui->rightButton->setEnabled(true);
    }
}

void TreatInfoView::on_backButton_clicked()
{
    this->close();
}
