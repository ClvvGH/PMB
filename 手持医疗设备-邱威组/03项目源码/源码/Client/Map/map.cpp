#include "map.h"
#include "ui_map.h"

map::map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPixmap pixmap = QPixmap("://map/1.jpg");
    ui->label->setPixmap(pixmap);
}

map::~map()
{
    delete ui;
}

void map::on_comboBox_activated(const QString &arg1)
{

    if(ui->comboBox->currentText() == "1"){
        QPixmap pixmap = QPixmap("://map/1.jpg");
        ui->label->setPixmap(pixmap);
    }else if(ui->comboBox->currentText() == "2"){
        QPixmap pixmap = QPixmap("://map/2.jpg");
        ui->label->setPixmap(pixmap);
    }else if(ui->comboBox->currentText() == "3"){
        QPixmap pixmap = QPixmap("://map/3.jpg");
        ui->label->setPixmap(pixmap);
    }

}

void map::on_pushButton_clicked()
{
    this->close();
}
