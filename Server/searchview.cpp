#include "ui_searchview.h"
#include "searchview.h"

SearchView::SearchView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchView)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

}

SearchView::~SearchView()
{
    delete ui;
}


//医生信息查询
void SearchView::on_pushButton_clicked()
{
 QString DId,name,sex,bornYear,department,tel,hireDate,passward,position;
 model->setTable("doctor");

 DId=ui->lineEdit_DId->text();
 name=ui->lineEdit_name->text();
 sex=ui->lineEdit_sex->text();
 bornYear=ui->lineEdit_bornYear->text();
 department=ui->lineEdit_department->text();
 tel=ui->lineEdit_tel->text();
 hireDate=ui->lineEdit_hireDate->text();
 passward=ui->lineEdit_passward->text();
 position=ui->lineEdit_position->text();

 if(ui->lineEdit_DId->text()!= "")
 {
    model->setFilter(QString("DId=%1").arg(DId));
 }
 if(ui->lineEdit_name->text()!= NULL)
 {
    model->setFilter(QString("name='%1'").arg(name));
 }
 if(ui->lineEdit_sex->text()!= NULL)
 {
    model->setFilter(QString("sex='%1'").arg(sex));
 }
 if(ui->lineEdit_bornYear->text()!= NULL)
 {
    model->setFilter(QString("bornYear='%1'").arg(bornYear));
 }
 if(ui->lineEdit_department->text()!= NULL)
 {
    model->setFilter(QString("department='%1'").arg(department));
 }
 if(ui->lineEdit_tel->text()!= NULL)
 {
    model->setFilter(QString("tel=%1").arg(tel));
 }
 if(ui->lineEdit_hireDate->text()!= NULL)
 {
    model->setFilter(QString("hireDate'=%1'").arg(hireDate));
 }
 if(ui->lineEdit_passward->text()!= NULL)
 {
    model->setFilter(QString("passward='%1'").arg(passward));
 }
 if(ui->lineEdit_position->text()!= NULL)
 {
    model->setFilter(QString("position='%1'").arg(position));
 }
 model->select();
 ui->tableView->setModel(model);

}

//病人信息查询
void SearchView::on_pushButton_3_clicked()
{
    QString p,n,t,b,pw,s;
    p=ui->lineEdit_PID->text();
    n=ui->lineEdit_NAME->text();
    t=ui->lineEdit_TEL->text();
    b=ui->lineEdit_BORNYEAR->text();
    pw=ui->lineEdit_PASSWARD->text();
    s=ui->lineEdit_SEX->text();
    model->setTable("patient");

    if(ui->lineEdit_PID->text()!=NULL)
    {
        model->setFilter(QString("PId=%1").arg(p));
    }
    if(ui->lineEdit_NAME->text()!=NULL)
    {
        model->setFilter(QString("name='%1'").arg(n));
    }
    if(ui->lineEdit_TEL->text()!=NULL)
    {
        model->setFilter(QString("tel=%1").arg(t));
    }
    if(ui->lineEdit_BORNYEAR->text()!=NULL)
    {
        model->setFilter(QString("bornYear='%1'").arg(b));
    }
    if(ui->lineEdit_PASSWARD->text()!=NULL)
    {
        model->setFilter(QString("passward='%1'").arg(pw));
    }
    if(ui->lineEdit_SEX->text()!=NULL)
    {
        model->setFilter(QString("sex='%1'").arg(s));
    }
    model->select();
    ui->tableView->setModel(model);
}

//体检信息查询
void SearchView::on_pushButton_5_clicked()
{
    QString DID,PID,VID,VALUE,DATE;
    DID=ui->lineEdit_diD->text();
    PID=ui->lineEdit_piD->text();
    VID=ui->lineEdit_viD->text();
    VALUE=ui->lineEdit_valuE->text();
    DATE=ui->lineEdit_datE->text();

    model->setTable("examination");

    if(ui->lineEdit_diD->text()!=NULL)
    {
        model->setFilter(QString("DId=%1").arg(PID));
    }
    if(ui->lineEdit_piD->text()!=NULL)
    {
        model->setFilter(QString("PId='%1'").arg(DID));
    }
    if(ui->lineEdit_viD->text()!=NULL)
    {
        model->setFilter(QString("VId=%1").arg(VID));
    }
    if(ui->lineEdit_valuE->text()!=NULL)
    {
        model->setFilter(QString("value=%1").arg(VALUE));
    }
    if(ui->lineEdit_datE->text()!=NULL)
    {
        model->setFilter(QString("date='%1'").arg(DATE));
    }

    model->select();
    ui->tableView->setModel(model);
}

//医疗信息查询
void SearchView::on_pushButton_7_clicked()
{
    QString did,pid,dis,des,pre,date;
    did=ui->lineEdit_did->text();
    pid=ui->lineEdit_pid->text();
    dis=ui->lineEdit_diseaseName->text();
    des=ui->lineEdit_description->text();
    pre=ui->lineEdit_prescription->text();
    date=ui->lineEdit_date->text();
    model->setTable("treatment");

    if(ui->lineEdit_did->text()!=NULL)
    {
        model->setFilter(QString("DId=%1").arg(did));
    }
    if(ui->lineEdit_pid->text()!=NULL)
    {
        model->setFilter(QString("PId=%1").arg(pid));
    }
    if(ui->lineEdit_diseaseName->text()!=NULL)
    {
        model->setFilter(QString("disessName='%1'").arg(dis));
    }
    if(ui->lineEdit_description->text()!=NULL)
    {
        model->setFilter(QString("description='%1'").arg(des));
    }
    if(ui->lineEdit_prescription->text()!=NULL)
    {
        model->setFilter(QString("prescription='%1'").arg(pre));
    }
    if(ui->lineEdit_date->text()!=NULL)
    {
        model->setFilter(QString("date='%1'").arg(date));
    }
    model->select();
    ui->tableView->setModel(model);

}
//索引到指定页面
void SearchView::on_DoctortoolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SearchView::on_PatienttoolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SearchView::on_ExaminationtoolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SearchView::on_TreatmenttoolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
