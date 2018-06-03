#include "selfinfoview.h"
#include "ui_selfinfoview.h"

SelfInfoView::SelfInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelfInfoView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    showInfo();
}

SelfInfoView::~SelfInfoView()
{
    delete ui;
}

void SelfInfoView::showInfo()
{
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getAndShowResult(QList<QVariantMap*>)));
    if (identity == 1)
    {
        ui->stackedWidget->setCurrentIndex(0);
        cc->sendSql("Select * from doctor where DId = '"+QString("%1").arg(ID)+"';",ChatClient::QUE);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        cc->sendSql("Select * from patient where PId = '"+QString("%1").arg(ID)+"';",ChatClient::QUE);
    }
}

void SelfInfoView::getAndShowResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getAndShowResult(QList<QVariantMap*>)));
    if (identity ==1)
    {
        ui->name->setText(resultSet.at(0)->take("name").toString());
        ui->sex->setCurrentIndex(ui->sex->findText(resultSet.at(0)->take("sex").toString()));
        ui->bornYear->setText(resultSet.at(0)->take("bornYear").toString());
        ui->age->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-ui->bornYear->text().toInt()+1));
        ui->tel->setText(resultSet.at(0)->take("tel").toString());
        ui->department->setCurrentIndex(ui->department->findText(resultSet.at(0)->take("department").toString()));
        ui->position->setCurrentIndex(ui->position->findText(resultSet.at(0)->take("position").toString()));
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        ui->name_2->setText(resultSet.at(0)->take("name").toString());
        ui->sex_2->setCurrentIndex(ui->sex->findText(resultSet.at(0)->take("sex").toString()));
        ui->bornYear_2->setText(resultSet.at(0)->take("bornYear").toString());
        ui->age_2->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-ui->bornYear->text().toInt()+1));
        ui->tel_2->setText(resultSet.at(0)->take("tel").toString());
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void SelfInfoView::getRightMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("修改个人信息成功");
    msgBox.exec();
}

void SelfInfoView::getErrorMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("修改失败，请重试");
    msgBox.exec();
}


void SelfInfoView::on_backButton_clicked()
{
    this->close();
}

void SelfInfoView::on_logoutButton_clicked()
{
    emit logout();
    this->close();

}

void SelfInfoView::on_securityButton_clicked()
{
    SecurityInfoView *siv = new SecurityInfoView();
    siv->show();
}

void SelfInfoView::on_editInfoButton_clicked()
{
    QRegExp nameRE("^.{0,10}$");
    QRegExp telRE("^[0-9]{0,20}");
    QRegExp bornYearRE("^[0-9]{4,4}");
    QMessageBox msgBox;
    if (identity == 1)
    {
        if (ui->name->text().isEmpty())
        {
            msgBox.setText("请输入姓名");
            msgBox.exec();
            ui->name->setFocus();
            return;
        }
        else if (!nameRE.exactMatch(ui->name->text()))
        {
            msgBox.setText("姓名格式错误，请重新输入");
            msgBox.exec();
            ui->name->setFocus();
            return;
        }
        if(ui->tel->text().isEmpty())
        {
            msgBox.setText("请输入联系方式");
            msgBox.exec();
            ui->tel->setFocus();
            return;
        }
        else if (!telRE.exactMatch(ui->tel->text()))
        {
            msgBox.setText("联系方式格式错误");
            msgBox.exec();
            ui->tel->setFocus();
            return;
        }
        if(ui->bornYear->text().isEmpty())
        {
            msgBox.setText("请输入出生年份");
            msgBox.exec();
            ui->bornYear->setFocus();
            return;
        }
        else if (!bornYearRE.exactMatch(ui->bornYear->text()))
        {
            msgBox.setText("出生年份格式错误");
            msgBox.exec();
            ui->bornYear->setFocus();
            return;
        }
        connect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
        connect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
        cc->sendSql("update doctor set name ='"+ui->name->text() +
                    "',sex = '"+ ui->sex->currentText()+
                    "',bornYear = '"+ui->bornYear->text() +
                    "',tel = '"+ui->tel->text()+
                    "',department ='" +ui->department->currentText()+
                    "',position ='" +ui->position->currentText()+"' where DId = '"+QString("%1").arg(ID)+"';",ChatClient::EXC);
    }
    else
    {
        if (ui->name_2->text().isEmpty())
        {
            msgBox.setText("请输入姓名");
            msgBox.exec();
            ui->name_2->setFocus();
            return;
        }
        else if (!nameRE.exactMatch(ui->name_2->text()))
        {
            msgBox.setText("姓名格式错误，请重新输入");
            msgBox.exec();
            ui->name_2->setFocus();
            return;
        }
        if(ui->tel_2->text().isEmpty())
        {
            msgBox.setText("请输入联系方式");
            msgBox.exec();
            ui->tel_2->setFocus();
            return;
        }
        else if (!telRE.exactMatch(ui->tel_2->text()))
        {
            msgBox.setText("联系方式格式错误");
            msgBox.exec();
            ui->tel_2->setFocus();
            return;
        }
        if(ui->bornYear_2->text().isEmpty())
        {
            msgBox.setText("请输入出生年份");
            msgBox.exec();
            ui->bornYear_2->setFocus();
            return;
        }
        else if (!bornYearRE.exactMatch(ui->bornYear_2->text()))
        {
            msgBox.setText("出生年份格式错误");
            msgBox.exec();
            ui->bornYear_2->setFocus();
            return;
        }
        connect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
        connect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
        cc->sendSql("update patient set name ='"+ui->name_2->text() +
                    "',sex = '"+ ui->sex_2->currentText()+
                    "',bornYear = '"+ui->bornYear_2->text() +
                    "',tel = '"+ui->tel_2->text()+
                    "' where PId = '"+QString("%1").arg(ID)+"';",ChatClient::EXC);
    }
}
