#include "patientlistview.h"
#include "ui_patientlistview.h"

PatientListView::PatientListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientListView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->hide();
}

PatientListView::~PatientListView()
{
    delete ui;
}

void PatientListView::on_queryButton_clicked()
{
    QString sql = "Select * From patient where '1' = '1'";
    if (!ui->id->text().isEmpty())
    {
        sql += "and PId ='" + ui->id->text()+"'";
    }
    if (!ui->name->text().isEmpty())
    {
        sql += "and name like '%"+ui->name->text()+"%'";
    }
    sql += ";";
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    cc->sendSql(sql,ChatClient::QUE);
}

void PatientListView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    if (resultSet.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有结果");
        msgBox.exec();
        ui->id->setFocus();
    }
    else
    {
        int row = resultSet.size();
        QStringList keys;
        ui->tableWidget->setRowCount(row);
        ui->tableWidget->setColumnCount(5);
        keys.append("编号");
        keys.append("姓名");
        keys.append("性别");
        keys.append("年龄");
        keys.append("详情");
        ui->tableWidget->setHorizontalHeaderLabels(keys);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        for (int i=0;i<row;i++)
        {
            QTableWidgetItem *id = new QTableWidgetItem();
            QTableWidgetItem *name = new QTableWidgetItem();
            QTableWidgetItem *sex = new QTableWidgetItem();
            QTableWidgetItem *age = new QTableWidgetItem();
            QTableWidgetItem *detail = new QTableWidgetItem();
            name->setTextAlignment(Qt::AlignCenter);
            sex->setTextAlignment(Qt::AlignCenter);
            age->setTextAlignment(Qt::AlignCenter);
            detail->setTextAlignment(Qt::AlignCenter);
            id->setText(QString("%1").arg(resultSet.at(i)->take("PId").toInt()));
            name->setText(resultSet.at(i)->take("name").toString());
            sex->setText(resultSet.at(i)->take("sex").toString());
            age->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-resultSet.at(i)->take("bornYear").toString().toInt()+1));
            detail->setIcon(QIcon(":/resource/jump.png"));
            ui->tableWidget->setItem(i,0,id);
            ui->tableWidget->setItem(i,1,name);
            ui->tableWidget->setItem(i,2,sex);
            ui->tableWidget->setItem(i,3,age);
            ui->tableWidget->setItem(i,4,detail);
            ui->tableWidget->hideColumn(0);
        }
    }
}

void PatientListView::on_tableWidget_clicked(const QModelIndex &index)
{
    PatientInfoView *piv = new PatientInfoView(ui->tableWidget->item(index.row(),0)->text().toInt());
    piv->show();
}

void PatientListView::on_backButton_clicked()
{
    this->close();
}
