#include "patientregisterview.h"
#include "ui_patientregisterview.h"

PatientRegisterView::PatientRegisterView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientRegisterView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

PatientRegisterView::~PatientRegisterView()
{
    delete ui;
}

void PatientRegisterView::on_confirm_clicked()
{
    QRegExp usernameRE("^[a-zA-Z]{1}.{5,20}");
    QRegExp passwordRE("^[a-zA-Z]{1}.{5,20}");
    QRegExp nameRE("^.{0,10}$");
    QRegExp telRE("^[0-9]{0,20}");
    QRegExp bornYearRE("^[0-9]{4,4}");
    bool flag;
    flag = true;
    if(ui->username->text().isEmpty())
    {
        ui->username->setStyleSheet("background-color:red");
        ui->tip->setText("请输入用户名");
        flag =0;
    }
    else if(!usernameRE.exactMatch(ui->username->text()))
    {
        ui->username->setStyleSheet("background-color:red");
        ui->tip->setText("密码必须以字母开头，大于6位小于20位");
        flag =0;
    }
    if(ui->password->text().isEmpty())
    {
        ui->password->setStyleSheet("background-color:red");
        ui->tip->setText("请输入密码");
        flag =0;
    }
    else if(!passwordRE.exactMatch(ui->password->text()))
    {
        ui->password->setStyleSheet("background-color:red");
        ui->tip->setText("密码必须以字母开头，大于6位小于20位");
        flag =0;
    }
    if(ui->confirm_password->text().isEmpty()){
        ui->confirm_password->setStyleSheet("background-color:red");
        ui->tip->setText("请确认密码");
        flag =0;
    }
    else if(QString::compare(ui->confirm_password->text(),ui->password->text())!= 0){
        ui->password->setStyleSheet("background-color:red");
        ui->confirm_password->setStyleSheet("background-color:red");
        ui->tip->setText("两次输入的密码不一致");
        flag =0;
    }
    if(ui->name->text().isEmpty()){
        ui->name->setStyleSheet("background-color:red");
        ui->tip->setText("请输入姓名");
        flag =0;
    }
    else if(!nameRE.exactMatch(ui->name->text()))
    {
        ui->name->setStyleSheet("background-color:red");
        ui->tip->setText("姓名格式错误");
        flag =0;
    }
    if(ui->sex->currentText() == NULL){
        ui->sex->setStyleSheet("background-color:red");
        ui->tip->setText("请选择性别");
        flag =0;
    }
    if(ui->phoneNo->text().isEmpty()){
        ui->phoneNo->setStyleSheet("background-color:red");
        ui->tip->setText("请输入联系方式");
        flag =0;
    }
    else if (!telRE.exactMatch(ui->phoneNo->text()))
    {
        ui->phoneNo->setStyleSheet("background-color:red");
        ui->tip->setText("联系方式格式错误");
        flag =0;
    }
    if(ui->bornYear->text().isEmpty())
    {
        ui->bornYear->setStyleSheet("background-color:red");
        ui->tip->setText("请输入出生年份");
        flag =0;
    }
    else if (!bornYearRE.exactMatch(ui->bornYear->text()))
    {
        ui->phoneNo->setStyleSheet("background-color:red");
        ui->tip->setText("请输入4位数字出生年份");
        flag =0;
    }
    if(flag)
    {
        connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
        cc->sendSql("Select * from patient where username = '"+ui->username->text()+"';",ChatClient::QUE);
    }
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
        ui->tip->setText("");
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
    this->accept();
}
