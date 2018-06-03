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
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    cc->sendSql("Select * from treatment  natural join doctor where PId = '" +QString("%1").arg(PId)+"';",ChatClient::QUE);
}

TreatInfoView::~TreatInfoView()
{
    delete ui;
}

void TreatInfoView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    ui->DId->setText(QString("%1").arg(resultSet.at(row)->take("DId").toInt()));
    ui->doctorName->setText(resultSet.at(row)->take("name").toString());
    ui->disease->setText(resultSet.at(row)->take("diseaseName").toString());
    ui->date->setText(resultSet.at(row)->take("date").toString());
    ui->advice->setPlainText(resultSet.at(row)->take("advice").toString());
    ui->description->setPlainText(resultSet.at(row)->take("description").toString());
    ui->prescription->setPlainText(resultSet.at(row)->take("prescription").toString());
    ui->diagnose->setPlainText(resultSet.at(row)->take("diagnose").toString());
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
