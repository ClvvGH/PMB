#include "sceince.h"
#include "ui_sceince.h"

SCEINCE::SCEINCE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SCEINCE)
{
    ui->setupUi(this);
}

SCEINCE::~SCEINCE()
{
    delete ui;
}
