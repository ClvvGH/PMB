#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    setItemEnable(false);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(passwordCorrect()),this,SLOT(login()));
    connect(this,SIGNAL(passwordWrong()),this,SLOT(sendWrongMessage()));
}

LoginView::~LoginView()
{
    delete ui;
}
//按下登陆按钮
void LoginView::on_LoginButton_clicked()
{
    bool flag = 1;
    if(ui->password->text().isEmpty())
    {
        flag =0;
    }
    if(ui->username->text().isEmpty())
    {
        flag =0;
    }
    if(flag && ui->DoctorButton->isChecked())
    {
        connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
        cc->sendSql("select * from doctor where username = '"+ui->username->text()+"' && password ='"+ui->password->text()+"';",ChatClient::QUE);
    }
    else if (flag && ui->PatientButton->isChecked())
    {
        connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
        cc->sendSql("select * from patient where username = '"+ui->username->text()+"' && password ='"+ui->password->text()+"';",ChatClient::QUE);
    }
}
//获取服务器返回数据，当服务器传回数据时被调用
void LoginView::getResult(QJsonArray arr)
{
    if(!arr.isEmpty())
    {
        qDebug() << "密码验证正确";
        if (ui->DoctorButton->isChecked())
        {
            ID = arr.at(0).toObject().take("DId").toInt();
        }
        else
        {
            ID = arr.at(0).toObject().take("PId").toInt();
        }
        emit passwordCorrect();
    }
    else
    {
        emit passwordWrong();
    }
    disconnect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
}

void LoginView::on_Quitbutton_clicked()
{
    this->reject();
}

//跳转到注册界面
void LoginView::on_RegisterButton_clicked()
{
    if(ui->DoctorButton->isChecked())
    {
        DoctorRegisterView drv;
        drv.exec();
    }
    else if (ui->PatientButton->isChecked())
    {
        PatientRegisterView prv;
        prv.exec();
    }
    else
    {
        qDebug() << "error";
    }
}

void LoginView::on_DoctorButton_clicked()
{
    setItemEnable(true);
    ui->username->setFocus();
}

void LoginView::setItemEnable(bool flag)
{
    ui->LoginButton->setEnabled(flag);
    ui->RegisterButton->setEnabled(flag);
    ui->username->setEnabled(flag);
    ui->password->setEnabled(flag);
}

void LoginView::on_PatientButton_clicked()
{
    setItemEnable(true);
    ui->username->setFocus();
}
//执行登陆
void LoginView::login()
{
    if (ui->DoctorButton->isChecked())
    {
        identity = 1;
        DoctorMainView *dmv = new DoctorMainView();
        dmv->show();
        this->close();
    }
    else if (ui->PatientButton->isChecked())
    {
        identity = 2;
        PatientMainView *pmv = new PatientMainView();
        pmv->show();
        this->close();
    }
    else
    {
        qDebug() << "error";
    }
}

void LoginView::sendWrongMessage()
{
    QMessageBox msgBox;
    msgBox.setText("用户名密码错误");
    msgBox.exec();
    ui->password->setText("");
    ui->username->setText("");
    ui->username->setFocus();
}
