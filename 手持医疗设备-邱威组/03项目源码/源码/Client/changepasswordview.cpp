 #include "changepasswordview.h"
#include "ui_changepasswordview.h"

ChangePasswordView::ChangePasswordView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePasswordView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

ChangePasswordView::~ChangePasswordView()
{
    delete ui;
}

void ChangePasswordView::on_pushButton_clicked()
{
    bool flag = true;
    QRegExp passwordRE("^[a-zA-Z]{1}.{5,20}");
    if (ui->elderPassword->text().isEmpty())
    {
        //ui->elderPassword->setStyleSheet("");
        ui->tip->setText("请输入旧密码");
        flag = false;
    }
    if (ui->newPassword->text().isEmpty())
    {
        ui->tip->setText("请设置新密码");
        flag =false;
    }
    else if (!passwordRE.exactMatch(ui->newPassword->text()))
    {
        ui->tip->setText("密码格式错误");
        flag = false;
    }
    if (ui->confirmPassword->text().isEmpty())
    {
        ui->tip->setText("请确认密码");
        flag = false;
    }
    else if (QString::compare(ui->confirmPassword->text(),ui->newPassword->text())!=0)
    {
        ui->tip->setText("两次输入的密码不一致");
        flag = false;
    }
    if(flag)
    {
        connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(checkPassword(QList<QVariantMap*>)));
        if (identity ==1)
        {
            cc->sendSql("Select * from doctor where DId = '"+QString("%1").arg(ID)+"' and password='"+ui->elderPassword->text()+"';",ChatClient::QUE);
        }
        else
        {
            cc->sendSql("Select * from patient where PId = '"+QString("%1").arg(ID)+"' and password='"+ui->elderPassword->text()+"';",ChatClient::QUE);
        }
    }
}

void ChangePasswordView::getErrorMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("修改密码出错，请重试");
    msgBox.exec();
}
void ChangePasswordView::getRightMessage()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
    QMessageBox msgBox;
    msgBox.setText("修改密码成功");
    msgBox.exec();
    this->close();
}

void ChangePasswordView::checkPassword(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(checkPassword(QList<QVariantMap*>)));
    if (resultSet.isEmpty())
    {
        passwordError();
    }
    else
    {
        connect(cc,SIGNAL(excSuccessfully()),this,SLOT(getRightMessage()));
        connect(cc,SIGNAL(failedInExc()),this,SLOT(getErrorMessage()));
        if (identity == 1)
        {
            cc->sendSql("Update doctor set password = '"+ui->newPassword->text()+"' where DId='"+QString("%1").arg(ID)+"';",ChatClient::EXC);

        }
        else
        {
            cc->sendSql("update patient set password = '"+ui->newPassword->text()+"' where PId = '"+QString("%1").arg(ID)+"';",ChatClient::EXC);
        }
    }
}

void ChangePasswordView::passwordError()
{
    QMessageBox msgBox;
    msgBox.setText("旧密码错误，请重新输入");
    msgBox.exec();
    ui->newPassword->setText("");
    ui->elderPassword->setText("");
    ui->confirmPassword->setText("");
}

void ChangePasswordView::on_backButton_clicked()
{
    this->close();
}
