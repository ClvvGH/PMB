#include "examinationinfoview.h"
#include "ui_examinationinfoview.h"

ExaminationInfoView::ExaminationInfoView(int PId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExaminationInfoView)
{
    this->PId = PId;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->hide();
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    cc->sendSql(QString("Select * from examination natural join variable where PId = '" +QString("%1").arg(PId)+"';"),ChatClient::QUE);
}

ExaminationInfoView::~ExaminationInfoView()
{
    delete ui;
}

void ExaminationInfoView::getResult(QList<QVariantMap *> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    int row = resultSet.size();
    QStringList keys;
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(4);
    keys.append("指标名称");
    keys.append("数值");
    keys.append("单位");
    keys.append("时间");
    ui->tableWidget->setHorizontalHeaderLabels(keys);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i=0;i<row;i++)
    {
        QTableWidgetItem *name = new QTableWidgetItem();
        QTableWidgetItem *date = new QTableWidgetItem();
        QTableWidgetItem *value = new QTableWidgetItem();
        QTableWidgetItem *unit = new QTableWidgetItem();
        name->setTextAlignment(Qt::AlignCenter);
        date->setTextAlignment(Qt::AlignCenter);
        value->setTextAlignment(Qt::AlignCenter);
        unit->setTextAlignment(Qt::AlignCenter);
        name->setText(resultSet.at(i)->take("name").toString());
        value->setText(resultSet.at(i)->take("value").toString());
        date->setText(resultSet.at(i)->take("date").toString());
        unit->setText(resultSet.at(i)->take("unit").toString());
        ui->tableWidget->setItem(i,0,name);
        ui->tableWidget->setItem(i,1,value);
        ui->tableWidget->setItem(i,2,unit);
        ui->tableWidget->setItem(i,3,date);
    }
}

void ExaminationInfoView::on_backButton_clicked()
{
    this->close();
}
