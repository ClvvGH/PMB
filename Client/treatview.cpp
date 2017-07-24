#include "treatview.h"
#include "ui_treatview.h"

TreatView::TreatView(int PId,QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreatView)
{
    this->PId = PId;
    this->name = name;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->stackedWidget->setCurrentIndex(0);
    ui->leftButton->setEnabled(false);
    ui->name->setText(name);
}

TreatView::~TreatView()
{
    delete ui;
}

void TreatView::on_leftButton_clicked()
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

void TreatView::on_rightButton_clicked()
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

void TreatView::on_backButton_clicked()
{
    this->close();
}

void TreatView::on_submitButton_clicked()
{
    if (ui->diagnose->toPlainText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("诊断信息为空");
        ui->diagnose->setFocus();
        return;
    }
    if (ui->description->toPlainText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("病情描述为空");
        ui->description->setFocus();
        return;
    }
    if (ui->advice->toPlainText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("建议为空");
        ui->advice->setFocus();
        return;
    }
    if (ui->prescription->toPlainText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("处方为空");
        ui->prescription->setFocus();
        return;
    }
    if (ui->disease->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("病因为空");
        ui->disease->setFocus();
        return;
    }
    connect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    connect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    cc->sendSql("Insert into treatment(PId,DId,description,diagnose,prescription,diseaseName,advice,date)"
                "values ('"+QString("%1").arg(PId)+"', '"+QString("%1").arg(ID)+"', '"+
                ui->description->toPlainText()+"', '"+ui->diagnose->toPlainText()+"', '"+
                ui->prescription->toPlainText()+"', '"+ui->disease->text()+"', '"+
                ui->advice->toPlainText()+"', '"+QDate::currentDate().toString("yyyy-MM-dd")+"') ;",ChatClient::EXC);
}

void TreatView::getRightMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("提交成功");
    msgBox.exec();
    this->close();
}
void TreatView::getErrorMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("提交失败，请重试");
    msgBox.exec();
}
