#include "temperatureview.h"
#include "ui_temperatureview.h"
TemperatureView::TemperatureView(int PId,QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureView)
{
    this->PId = PId;
    this->name = name;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->name->setText(name);
}

TemperatureView::~TemperatureView()
{
    delete ui;
}

void TemperatureView::on_checkButton_released()
{
    int fd;
    fd=open("dev/adc",0);
    if ( fd < 0 ) {
    }
    ui->value->clear();
    char buf[32];//读取的缓冲数据
    memset(buf,0,32);
    if(read(fd, buf, 32)<0)
    {
    }
    ui->value->setText(tr(buf));
}

void TemperatureView::on_saveButton_released()
{
    if(ui->value->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("请先获得数据");
        msgBox.exec();
    }
    connect(cc,SIGNAL(excSuccessfully()),this,SLOT(Success()));
    connect(cc,SIGNAL(failedInExc()),this,SLOT(failed()));
    cc->sendSql(QString("insert into examination values ('"+QString("%1").arg(ID)+"','"+QString("%1").arg(PId)+"','1','"+ui->value->text()+"','"+
                QDate::currentDate().toString("yyyy-MM-dd")+"');"),ChatClient::EXC);
}

void TemperatureView::Success()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(Success()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(failed()));
    QMessageBox msgBox;
    msgBox.setText("添加体检信息成功");
    msgBox.exec();
}

void TemperatureView::failed()
{
    disconnect(cc,SIGNAL(excSuccessfully()),this,SLOT(Success()));
    disconnect(cc,SIGNAL(failedInExc()),this,SLOT(failed()));
    QMessageBox msgBox;
    msgBox.setText("添加失败，请重试");
    msgBox.exec();
}

void TemperatureView::on_backButton_released()
{
    this->close();
}
