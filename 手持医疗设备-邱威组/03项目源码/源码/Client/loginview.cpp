#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    setItemEnable(false);
    ui->confirm->setShortcut(Qt::Key_Enter);
    ui->confirm->setShortcut( QKeySequence::InsertParagraphSeparator );
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(passwordCorrect()),this,SLOT(login()));
    connect(this,SIGNAL(passwordWrong()),this,SLOT(sendWrongMessage()));
}

LoginView::~LoginView()
{
    delete ui;
}
//按下登陆按钮
void LoginView::on_confirm_clicked()
{
    bool flag = 1;
    QMessageBox msgBox;
    if(ui->username->text().isEmpty())
    {
        msgBox.setText("请输入账号");
        msgBox.exec();
        flag =0;
    }
    if(ui->password->text().isEmpty())
    {
        msgBox.setText("请输入密码");
        msgBox.exec();
        flag =0;
    }
    if(flag && ui->DoctorButton->isChecked())
    {
        connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
        cc->sendSql("select * from doctor where username = '"+ui->username->text()+"' && password ='"+ui->password->text()+"';",ChatClient::QUE);
    }
    else if (flag && ui->PatientButton->isChecked())
    {
        connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
        cc->sendSql("select * from patient where username = '"+ui->username->text()+"' && password ='"+ui->password->text()+"';",ChatClient::QUE);
    }
}
//获取服务器返回数据，当服务器传回数据时被调用
void LoginView::getResult(QList<QVariantMap*> resultSet)
{
    if(!resultSet.isEmpty())
    {
        if (ui->DoctorButton->isChecked())
        {
            ID = resultSet.at(0)->take("DId").toInt();//notices! whether the data is int type
        }
        else
        {
            ID = resultSet.at(0)->take("PId").toInt();
        }
        emit passwordCorrect();
    }
    else
    {
        emit passwordWrong();
    }
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
}

void LoginView::on_cancel_clicked()
{
    this->close();
}

//跳转到注册界面
void LoginView::on_RegisterButton_clicked()
{
    if(ui->DoctorButton->isChecked())
    {
        DoctorRegisterView *drv = new DoctorRegisterView();
        drv->show();
    }
    else if (ui->PatientButton->isChecked())
    {
        PatientRegisterView *prv = new PatientRegisterView();
        prv->show();
    }
    else
    {
    }
}

void LoginView::on_DoctorButton_clicked()
{
    setItemEnable(true);
    ui->username->setFocus();
}

void LoginView::setItemEnable(bool flag)
{
    ui->confirm->setEnabled(flag);
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
