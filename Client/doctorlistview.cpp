#include "doctorlistview.h"
#include "ui_doctorlistview.h"

DoctorListView::DoctorListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorListView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getAndSetResult(QJsonArray)));
    cc->sendSql("select * from doctor",ChatClient::QUE);

}

DoctorListView::~DoctorListView()
{
    delete ui;
}

void DoctorListView::getAndSetResult(QJsonArray arr)
{
    int row = arr.size();
    QStringList keys;
    keys.append("姓名");
    keys.append("性别");
    keys.append("部门");
    keys.append("职位");
    keys.append("联系方式");
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(keys);
    for (int i=0;i<row;i++)
    {
        QTableWidgetItem *name = new QTableWidgetItem();
        QTableWidgetItem *sex = new QTableWidgetItem();
        QTableWidgetItem *department = new QTableWidgetItem();
        QTableWidgetItem *position = new QTableWidgetItem();
        QTableWidgetItem *tel = new QTableWidgetItem();
        name->setText(arr.at(i).toObject().take("name").toString());
        sex->setText(arr.at(i).toObject().take("sex").toString());
        department->setText(arr.at(i).toObject().take("department").toString());
        position->setText(arr.at(i).toObject().take("position").toString());
        tel->setText(arr.at(i).toObject().take("tel").toString());
        ui->tableWidget->setItem(i,0,name);
        ui->tableWidget->setItem(i,1,sex);
        ui->tableWidget->setItem(i,2,department);
        ui->tableWidget->setItem(i,3,position);
        ui->tableWidget->setItem(i,4,tel);
    }
}

void DoctorListView::on_pushButton_clicked()
{
    this->close();
}
