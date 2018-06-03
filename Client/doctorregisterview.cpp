#include "doctorregisterview.h"
#include "ui_doctorregisterview.h"

extern ChatClient *cc;

DoctorRegisterView::DoctorRegisterView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorRegisterView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tip->setStyleSheet("color:red");
    ui->dateEdit->setDate(QDate::currentDate());
    connect(this,SIGNAL(accessibleUsername()),this,SLOT(doRegister()));
    connect(this,SIGNAL(usernameExist()),this,SLOT(sendMessage()));
}

//确认
void DoctorRegisterView::on_confirm_clicked()
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
    if(ui->office->currentText() == NULL){
        ui->office->setStyleSheet("background-color:red");
        ui->tip->setText("请选择所在部门");
        flag =0;
    }
    if(ui->position->currentText() == NULL){
        ui->position->setStyleSheet("background-color:red");
        ui->tip->setText("请选择职位");
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
        cc->sendSql("Select * from doctor where username = '"+ui->username->text()+"';",ChatClient::QUE);
    }
}

void DoctorRegisterView::on_password_editingFinished()
{
    ui->password->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_sex_activated(int index)
{
    ui->sex->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_office_activated(int index)
{
    ui->office->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_confirm_password_editingFinished()
{
    ui->confirm_password->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_name_editingFinished()
{
    ui->name->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_position_activated(int index)
{
    ui->position->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_phoneNo_editingFinished()
{
    ui->phoneNo->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_username_editingFinished()
{
    ui->username->setStyleSheet("background-color:white");
}

void DoctorRegisterView::on_bornYear_editingFinished()
{
    ui->bornYear->setStyleSheet("background-color:white");
}
//注册成功
void DoctorRegisterView::registerSuccessfully()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(registerSuccessfully()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(registerFailed()));
    QMessageBox msgBox;
    DoctorRegisterView drv;
    msgBox.setText("注册成功");
    msgBox.exec();
    this->accept();
    drv.show();
}
//注册失败
void DoctorRegisterView::registerFailed()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(registerSuccessfully()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(registerFailed()));
    QMessageBox msgBox;
    msgBox.setText("注册失败，请重试");
    msgBox.exec();
    ui->username->setText("");
    ui->password->setText("");
    ui->confirm_password->setText("");
    ui->username->setFocus();
}
//当服务器传回数据时被调用
void DoctorRegisterView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    qDebug() << resultSet.size();
    if(resultSet.isEmpty())
    {
        qDebug() << "accessible ??";
        emit accessibleUsername();
    }
    else
    {
        emit usernameExist();
    }
}
//用户名未被注册，确认注册该用户，让用户名验证通过时被调用
void DoctorRegisterView::doRegister()
{
    connect(cc,SIGNAL(excSuccessfully()),this,SLOT(registerSuccessfully()));
    connect(cc,SIGNAL(failedInExc()),this,SLOT(registerFailed()));
    cc->sendSql(QString("Insert into doctor(username,password,name,sex,bornYear,department,tel,hireDate,position) values('"+
                ui->username->text()+"','"+ui->password->text()+"','"+
                ui->name->text()+"','"+ui->sex->currentText()+"','"+ui->bornYear->text()+"','"+ui->office->currentText()+
                "','"+ui->phoneNo->text()+"','"+ui->dateEdit->date().toString("yyyy-MM-dd")+"','"+ui->position->currentText()+"');"),ChatClient::EXC);
    ui->tip->setText("");
}
//当用户名验证已存在时被调用
void DoctorRegisterView::sendMessage()
{
    QMessageBox msgBox;
    msgBox.setText("用户名已存在，请重新输入");
    msgBox.exec();
    ui->username->setText("");
    ui->password->setText("");
    ui->confirm_password->setText("");
    ui->username->setFocus();
}

DoctorRegisterView::~DoctorRegisterView()
{
    delete ui;
}
//取消
void DoctorRegisterView::on_cancel_clicked()
{
    this->reject();
}
