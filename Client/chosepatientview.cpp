#include "chosepatientview.h"
#include "ui_chosepatientview.h"

ChosePatientView::ChosePatientView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChosePatientView)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->hide();
}

ChosePatientView::~ChosePatientView()
{
    delete ui;
}

void ChosePatientView::on_queryButton_clicked()
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
    connect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    cc->sendSql(sql,ChatClient::QUE);
}

void ChosePatientView::getResult(QJsonArray arr)
{
    disconnect(cc,SIGNAL(getResultSet(QJsonArray)),this,SLOT(getResult(QJsonArray)));
    if (arr.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有结果");
        msgBox.exec();
        ui->id->setFocus();
    }
    else
    {
        int row = arr.size();
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
            id->setText(QString("%1").arg(arr.at(i).toObject().take("PId").toInt()));
            name->setText(arr.at(i).toObject().take("name").toString());
            sex->setText(arr.at(i).toObject().take("sex").toString());
            age->setText(QString("%1").arg(QDate::currentDate().toString("yyyy").toInt()-arr.at(i).toObject().take("bornYear").toInt()+1));
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

void ChosePatientView::on_tableWidget_clicked(const QModelIndex &index)
{
    TreatView *tv = new TreatView(ui->tableWidget->item(index.row(),0)->text().toInt(),ui->tableWidget->item(index.row(),1)->text());
    tv->show();
}

void ChosePatientView::on_backButton_clicked()
{
    this->close();
}
