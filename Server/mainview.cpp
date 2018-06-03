#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    queryModel= new QSqlQueryModel();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(820,560);
    setItemEnable(false);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::setItemEnable(bool flag)
{
    ui->sortBox->setEnabled(flag);
    ui->insertButton->setEnabled(flag);
    ui->stackedWidget->setEnabled(flag);
    ui->deleteButton->setEnabled(flag);
    ui->saveButton->setEnabled(flag);
    ui->revokeButton->setEnabled(flag);
}



//显示医生信息
void MainView::on_doctorButton_clicked()
{
    model->setTable("doctor");
    setDoctorModel();
    ui->tableView->setModel(model);
    ui->stackedWidget->setCurrentIndex(0);
    setItemEnable(true);
}
//显示病人信息
void MainView::on_PatientButton_clicked()
{
    model->setTable("patient");
    setPatientModel();
    ui->stackedWidget->setCurrentIndex(2);
    setItemEnable(true);
}
//联表显示医疗信息
void MainView::on_TreatmentButton_clicked()
{
    //queryModel->setQuery("Select * From treatment natural join doctor natural join patient;");
    model->setTable("treatment");
    setTreatmentModel();
    //ui->tableView->setModel(queryModel);
    ui->stackedWidget->setCurrentIndex(1);
    setItemEnable(true);
}
//联表显示检查信息
void MainView::on_examinationButton_clicked()
{
    model->setTable("examination");
    queryModel->setQuery("Select * From examination natural join doctor natural join patient natural join variable;");
    setExaminationModel();
    //ui->tableView->setModel(queryModel);
    ui->stackedWidget->setCurrentIndex(3);
    setItemEnable(true);
}
//显示通信信息
void MainView::on_socketButton_clicked()
{
    model->setTable("clientAction");
    setSocketModel();
    setItemEnable(true);
    ui->stackedWidget->setEnabled(false);
}
//排序
void MainView::on_sortButton_clicked()
{

    if(ui->ASC->isChecked()==true)
    {
        model->setSort(0, Qt::AscendingOrder);
        model->select();
        ui->tableView->setModel(model);
    }
    if(ui->DESC->isChecked()==true)
    {
        model->setSort(0, Qt::DescendingOrder);
        model->select();
        ui->tableView->setModel(model);
    }
}
//插入
void MainView::on_insertButton_clicked()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
}
//保存
void MainView::on_saveButton_clicked()
{
    model->database().transaction();
    if(model->submitAll())
    {

       model->database().commit();
    }
    else
    {
        model->database().rollback();
        QMessageBox::warning(this,"未添加到数据库",tr("错误信息：%1").arg(model->lastError().text()));
    }
}
//删除
void MainView::on_deleteButton_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    model->removeRow(curRow);
}
//撤销
void MainView::on_revokeButton_clicked()
{
    model->revertAll();
}
//条件查询医生信息
void MainView::on_doctorQueryButton_clicked()
{
    QString DId,name,sex,bornYear,department,tel,hireDate,position;
     model->setTable("doctor");
     DId=ui->lineEdit_DId->text();
     name=ui->lineEdit_name->text();
     sex=ui->lineEdit_sex->text();
     bornYear=ui->lineEdit_bornYear->text();
     department=ui->lineEdit_department->text();
     tel=ui->lineEdit_tel->text();
     hireDate=ui->lineEdit_hireDate->text();
     position=ui->lineEdit_position->text();
     if(ui->lineEdit_DId->text()!= "")
     {
        model->setFilter(QString("DId = %1").arg(DId));
     }
     if(ui->lineEdit_name->text()!= NULL)
     {
        model->setFilter(QString("name like '%%1%'").arg(name));
     }
     if(ui->lineEdit_sex->text()!= NULL)
     {
        model->setFilter(QString("sex ='%1'").arg(sex));
     }
     if(ui->lineEdit_bornYear->text()!= NULL)
     {
        model->setFilter(QString("bornYear = %1").arg(bornYear));
     }
     if(ui->lineEdit_department->text()!= NULL)
     {
        model->setFilter(QString("department like '%%1%'").arg(department));
     }
     if(ui->lineEdit_tel->text()!= NULL)
     {
        model->setFilter(QString("tel=%1").arg(tel));
     }
     if(ui->lineEdit_hireDate->text()!= NULL)
     {
        model->setFilter(QString("hireDate= '%1'").arg(hireDate));
     }
     if(ui->lineEdit_position->text()!= NULL)
     {
        model->setFilter(QString("position like '%%1%'").arg(position));
     }
     setDoctorModel();
}

//条件查询医疗信息
void MainView::on_treatmentQueryButton_clicked()
{
    QString did,pid,dis,date;
    did=ui->lineEdit_did->text();
    pid=ui->lineEdit_pid->text();
    dis=ui->lineEdit_diseaseName->text();
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
    if(ui->lineEdit_date->text()!=NULL)
    {
        model->setFilter(QString("date='%1'").arg(date));
    }
    setTreatmentModel();

}

//条件查询患者信息
void MainView::on_patientQueryButton_clicked()
{
    QString p,n,t,b,pw,s;
    p=ui->lineEdit_PID->text();
    n=ui->lineEdit_NAME->text();
    t=ui->lineEdit_TEL->text();
    b=ui->lineEdit_BORNYEAR->text();
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

    if(ui->lineEdit_SEX->text()!=NULL)
    {
        model->setFilter(QString("sex='%1'").arg(s));
    }
    setPatientModel();
}
//条件查询检查信息
void MainView::on_ExaminationQueryButton_clicked()
{
    QString DID,PID;
    DID=ui->lineEdit_diD->text();
    PID=ui->lineEdit_piD->text();

    model->setTable("examination");

    if(ui->lineEdit_diD->text()!=NULL)
    {
        model->setFilter(QString("DId=%1").arg(PID));
    }
    if(ui->lineEdit_piD->text()!=NULL)
    {
        model->setFilter(QString("PId='%1'").arg(DID));
    }
    setExaminationModel();
}
//检查信息模型
void MainView::setExaminationModel()
{
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"医生编号");
    model->setHeaderData(1,Qt::Horizontal,"患者编号");
    model->setHeaderData(2,Qt::Horizontal,"性别");
    model->setHeaderData(3,Qt::Horizontal,"出生年份");
    model->setHeaderData(4,Qt::Horizontal,"部门");
    model->setHeaderData(5,Qt::Horizontal,"联系方式");
    model->setHeaderData(6,Qt::Horizontal,"聘用时间");
    model->setHeaderData(7,Qt::Horizontal,"密码");
    model->setHeaderData(8,Qt::Horizontal,"职位");
    ui->tableView->setModel(model);
}
//医生信息模型
void MainView::setDoctorModel()
{
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"性别");
    model->setHeaderData(3,Qt::Horizontal,"出生年份");
    model->setHeaderData(4,Qt::Horizontal,"部门");
    model->setHeaderData(5,Qt::Horizontal,"联系方式");
    model->setHeaderData(6,Qt::Horizontal,"聘用时间");
    model->setHeaderData(7,Qt::Horizontal,"密码");
    model->setHeaderData(8,Qt::Horizontal,"职位");
    model->setHeaderData(9,Qt::Horizontal,"用户名");
    ui->tableView->setModel(model);
}
//服务器记录模型
void MainView::setSocketModel()
{
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"客户端ip地址");
    model->setHeaderData(2,Qt::Horizontal,"活动");
    model->setHeaderData(3,Qt::Horizontal,"时间");
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,120);
}
//病人信息模型
void MainView::setPatientModel()
{
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"用户名");
    model->setHeaderData(2,Qt::Horizontal,"姓名");
    model->setHeaderData(3,Qt::Horizontal,"联系方式");
    model->setHeaderData(4,Qt::Horizontal,"出生年份");
    model->setHeaderData(5,Qt::Horizontal,"密码");
    model->setHeaderData(6,Qt::Horizontal,"性别");
    ui->tableView->setModel(model);
}
//检查信息模型
void MainView::setTreatmentModel()
{
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"医生编号");
    model->setHeaderData(1,Qt::Horizontal,"患者编号");
    model->setHeaderData(2,Qt::Horizontal,"疾病名称");
    model->setHeaderData(3,Qt::Horizontal,"病情描述");
    model->setHeaderData(3,Qt::Horizontal,"诊断");
    model->setHeaderData(3,Qt::Horizontal,"建议");
    model->setHeaderData(4,Qt::Horizontal,"处方");
    model->setHeaderData(5,Qt::Horizontal,"时间");
    ui->tableView->setModel(model);
}
