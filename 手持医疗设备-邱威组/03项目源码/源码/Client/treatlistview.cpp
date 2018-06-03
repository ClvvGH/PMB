#include "treatlistview.h"
#include "ui_treatlistview.h"

TreatListView::TreatListView(int PId,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreatListView)
{
    this->PId = PId;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->hide();
    connect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    cc->sendSql("Select * from treatment  natural join doctor where PId = '" +QString("%1").arg(PId)+"';",ChatClient::QUE);
}

TreatListView::~TreatListView()
{
    delete ui;
}

void TreatListView::on_backButton_clicked()
{
    this->close();
}

void TreatListView::getResult(QList<QVariantMap*> resultSet)
{
    disconnect(cc,SIGNAL(getResultSet(QList<QVariantMap*>)),this,SLOT(getResult(QList<QVariantMap*>)));
    int row = resultSet.size();
    QStringList keys;
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(4);
    keys.append("病因");
    keys.append("诊断医生");
    keys.append("时间");
    keys.append("详情");
    ui->tableWidget->setHorizontalHeaderLabels(keys);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i=0;i<row;i++)
    {
        QTableWidgetItem *disease = new QTableWidgetItem();
        QTableWidgetItem *doctorName = new QTableWidgetItem();
        QTableWidgetItem *date = new QTableWidgetItem();
        QTableWidgetItem *detail = new QTableWidgetItem();
        disease->setTextAlignment(Qt::AlignCenter);
        doctorName->setTextAlignment(Qt::AlignCenter);
        date->setTextAlignment(Qt::AlignCenter);
        detail->setTextAlignment(Qt::AlignCenter);
        disease->setText(resultSet.at(i)->take("diseaseName").toString());
        doctorName->setText(resultSet.at(i)->take("name").toString());
        date->setText(resultSet.at(i)->take("date").toString());
        detail->setIcon(QIcon(":/resource/jump.png"));
        ui->tableWidget->setItem(i,0,disease);
        ui->tableWidget->setItem(i,1,doctorName);
        ui->tableWidget->setItem(i,2,date);
        ui->tableWidget->setItem(i,3,detail);
    }
}

void TreatListView::on_tableWidget_clicked(const QModelIndex &index)
{
    TreatInfoView *tiv = new TreatInfoView(index.row(),PId);
    tiv->show();
}
