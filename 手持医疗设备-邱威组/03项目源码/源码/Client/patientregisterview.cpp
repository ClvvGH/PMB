#include "patientregisterview.h"
#include "ui_patientregisterview.h"

PatientRegisterView::PatientRegisterView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientRegisterView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

PatientRegisterView::~PatientRegisterView()
{
    delete ui;
}

void PatientRegisterView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    if (resultSet.isEmpty())
    {
        connect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
        connect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
        cc->sendSql("Insert into patient(username,password,name,sex,bornYear,tel) "
                    "values('"+ui->username->text()+"','"+ui->password->text()+"','"+
                    ui->name->text()+"','"+ui->sex->currentText()+"','"+ui->bornYear->text()+"','"+
                    ui->phoneNo->text()+"');",ChatClient::EXC);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("用户名已存在，请重新输入");
        msgBox.exec();
        ui->username->setText("");
        ui->password->setText("");
        ui->confirm_password->setText("");
        ui->username->setFocus();
    }
}

void PatientRegisterView::getErrorMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("注册失败，请重试");
    msgBox.exec();
    ui->username->setText("");
    ui->password->setText("");
    ui->confirm_password->setText("");
}

void PatientRegisterView::getRightMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("注册成功");
    msgBox.exec();
    this->close();
}

void PatientRegisterView::on_confirm_released()
{
    QRegExp usernameRE("^[a-zA-Z]{1}.{5,20}");
    QRegExp passwordRE("^[a-zA-Z]{1}.{5,20}");
    QRegExp nameRE("^.{0,10}$");
    QRegExp telRE("^[0-9]{0,20}");
    QRegExp bornYearRE("^[0-9]{4,4}");
    QMessageBox msgBox;
    if(ui->username->text().isEmpty())
    {
        ui->username->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入用户名");
        msgBox.exec();
        return;
    }
    else if(!usernameRE.exactMatch(ui->username->text()))
    {
        ui->username->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("用户名必须以字母开头，不少于6位");
        msgBox.exec();
        return;
    }
    if(ui->password->text().isEmpty())
    {
        ui->password->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入密码");
        msgBox.exec();
        return;
    }
    else if(!passwordRE.exactMatch(ui->password->text()))
    {
        ui->password->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("密码必须以字母开头，不少于6位");
        msgBox.exec();
        return;
    }
    if(ui->confirm_password->text().isEmpty()){
        ui->confirm_password->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请重复密码");
        msgBox.exec();
        return;
    }
    else if(QString::compare(ui->confirm_password->text(),ui->password->text())!= 0){
        ui->password->setStyleSheet("background-color:rgb(255, 92, 95)");
        ui->confirm_password->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("两次输入的密码不一致");
        msgBox.exec();
        return;
    }
    if(ui->name->text().isEmpty()){
        ui->name->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入姓名");
        msgBox.exec();
        return;
    }
    else if(!nameRE.exactMatch(ui->name->text()))
    {
        ui->name->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("姓名格式错误");
        msgBox.exec();
        return;
    }
    if(ui->phoneNo->text().isEmpty()){
        ui->phoneNo->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入联系方式");
        msgBox.exec();
        return;
    }
    else if (!telRE.exactMatch(ui->phoneNo->text()))
    {
        ui->phoneNo->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("联系方式格式错误");
        msgBox.exec();
        return;
    }
    if(ui->bornYear->text().isEmpty())
    {
        ui->bornYear->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入出生年份");
        msgBox.exec();
        return;
    }
    else if (!bornYearRE.exactMatch(ui->bornYear->text()))
    {
        ui->bornYear->setStyleSheet("background-color:rgb(255, 92, 95)");
        msgBox.setText("请输入4位出生年份");
        msgBox.exec();
        return;
    }
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    cc->sendSql("Select * from patient where username = '"+ui->username->text()+"';",ChatClient::QUE);
}

void PatientRegisterView::on_cancel_released()
{
    this->close();
}

void PatientRegisterView::on_username_editingFinished()
{
    ui->username->setStyleSheet("background-color:white");
}

void PatientRegisterView::on_password_editingFinished()
{
    ui->password->setStyleSheet("background-color:white");
}

void PatientRegisterView::on_confirm_password_editingFinished()
{
    ui->confirm_password->setStyleSheet("background-color:white");
}

void PatientRegisterView::on_name_editingFinished()
{
    ui->name->setStyleSheet("background-color:white");
}

void PatientRegisterView::on_bornYear_editingFinished()
{
    ui->bornYear->setStyleSheet("background-color:white");
}

void PatientRegisterView::on_phoneNo_editingFinished()
{
    ui->phoneNo->setStyleSheet("background-color:white");
}
