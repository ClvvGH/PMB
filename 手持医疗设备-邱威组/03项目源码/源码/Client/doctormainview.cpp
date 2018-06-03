#include "doctormainview.h"
#include "ui_doctormainview.h"

DoctorMainView::DoctorMainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorMainView)
{
    moveX = 0;
    rPoint = QPoint(0,0);
    ui->setupUi(this);
    ui->time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
    ui->page1->setPixmap(QPixmap(":/resource/selected.png"));
    page = 1;
    this->setWindowFlags(Qt::FramelessWindowHint);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //显示时间
    QTimer *timeTimer = new QTimer(this);
    connect(timeTimer,SIGNAL(timeout()),this,SLOT(showTime()));
    timeTimer->start(1000);
}

void DoctorMainView::showTime()
{
    ui->time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

DoctorMainView::~DoctorMainView()
{
    delete ui;
}


void DoctorMainView::logout()
{
    LoginView *lv =new LoginView();
    lv->show();
    this->close();
}

void DoctorMainView::mousePressEvent(QMouseEvent *event)
{
    startPoint = event->pos();
}
void DoctorMainView::mouseMoveEvent(QMouseEvent *event)
{
    nowPoint = event->pos();
    int rx = ((nowPoint.x()-startPoint.x())*160)/320;

    //ui->pushButton->move(ui->pushButton->pos().x()+rx,ui->pushButton->pos().y());
    ui->widget->move(ui->widget->pos().x()+rx,ui->widget->pos().y());
    rPoint.setX(rPoint.x()+rx);
    startPoint = event->pos();
}
void DoctorMainView::mouseReleaseEvent(QMouseEvent *event)
{
    if(rPoint.x()>=60)
    {
        if(page>1)
        {
            moveX = -rPoint.x()+320;
            timer->start(1);
            rPoint.setX(0);
            page-=1;
            setPageLogo();
        }
        else
        {
            moveX = -rPoint.x();
            timer->start(1);
            rPoint.setX(0);
        }
    }
    else if (rPoint.x()<=-60)
    {
        if(page<3)
        {
            moveX = -rPoint.x()-320;
            timer->start(1);
            rPoint.setX(0);
            page += 1;
            setPageLogo();
        }
        else
        {
            moveX = -rPoint.x();
            timer->start(1);
            rPoint.setX(0);
        }
    }
    else
    {
        moveX = -rPoint.x();
        timer->start(1);
        rPoint.setX(0);
    }
}
void DoctorMainView::setPageLogo()
{
    switch(page)
    {
        case 1:
            ui->page1->setPixmap(QPixmap(":/resource/selected.png"));
            ui->page2->setPixmap(QPixmap(":/resource/unSelected.png"));
            ui->page3->setPixmap(QPixmap(":/resource/unSelected.png"));
            break;
        case 2:
            ui->page1->setPixmap(QPixmap(":/resource/unSelected.png"));
            ui->page2->setPixmap(QPixmap(":/resource/selected.png"));
            ui->page3->setPixmap(QPixmap(":/resource/unSelected.png"));
            break;
        case 3:
            ui->page1->setPixmap(QPixmap(":/resource/unSelected.png"));
            ui->page2->setPixmap(QPixmap(":/resource/unSelected.png"));
            ui->page3->setPixmap(QPixmap(":/resource/selected.png"));
            break;
    }
}

void DoctorMainView::move()
{

    if(moveX<0)
    {
        ui->widget->move(ui->widget->pos().x()-1,ui->widget->y());
        moveX+=1;
    }
    else if (moveX>0)
    {
        ui->widget->move(ui->widget->pos().x()+1,ui->widget->y());
        moveX-=1;
    }
    else
    {
        timer->stop();
    }
}

void DoctorMainView::on_selfInfo_pressed()
{
    //ui->selfInfo->setGeometry(ui->selfInfo->x()+10,ui->selfInfo->y()+10,ui->selfInfo->width()-20,ui->selfInfo->height()-20);
    ui->selfInfo->setIconSize(QSize(40,40));
}

void DoctorMainView::on_selfInfo_clicked()
{
    ui->selfInfo->setIconSize(QSize(60,60));
    SelfInfoView *siv = new SelfInfoView();
    connect(siv,SIGNAL(logout()),this,SLOT(logout()));
    siv->show();
}

void DoctorMainView::on_calculator_pressed()
{
    ui->calculator->setIconSize(QSize(40,40));
}



void DoctorMainView::on_doctorList_pressed()
{
    ui->doctorList->setIconSize(QSize(40,40));
}

void DoctorMainView::on_patientInfo_pressed()
{
    ui->patientInfo->setIconSize(QSize(40,40));
}

void DoctorMainView::on_treat_pressed()
{
    ui->treat->setIconSize(QSize(40,40));
}

void DoctorMainView::on_examination_pressed()
{
    ui->examination->setIconSize(QSize(40,40));
}

void DoctorMainView::on_canleder_pressed()
{
    ui->canleder->setIconSize(QSize(40,40));
}

void DoctorMainView::on_weather_pressed()
{
    ui->weather->setIconSize(QSize(40,40));
    map *m = new map();
    m->show();
}

void DoctorMainView::on_painter_pressed()
{
    ui->painter->setIconSize(QSize(40,40));
}

void DoctorMainView::on_player_pressed()
{
    ui->player->setIconSize(QSize(40,40));
}

void DoctorMainView::on_logout_pressed()
{
    ui->logout->setIconSize(QSize(40,40));
}

void DoctorMainView::on_patientInfo_clicked()
{
    ui->patientInfo->setIconSize(QSize(60,60));
    PatientListView *plv = new PatientListView();
    plv->show();
}

void DoctorMainView::on_doctorList_clicked()
{
    ui->doctorList->setIconSize(QSize(60,60));
    DoctorListView *dlv = new DoctorListView();
    dlv->show();
}

void DoctorMainView::on_treat_clicked()
{
    ui->treat->setIconSize(QSize(60,60));
    ChosePatientView *cpv = new  ChosePatientView(0);
    cpv->show();
}

void DoctorMainView::on_examination_clicked()
{
    ui->examination->setIconSize(QSize(60,60));
    examinationList *el = new examinationList();
    el->show();
}

void DoctorMainView::on_canleder_clicked()
{
    ui->canleder->setIconSize(QSize(60,60));
}

void DoctorMainView::on_weather_clicked()
{
    ui->weather->setIconSize(QSize(60,60));
}

void DoctorMainView::on_painter_clicked()
{
    ui->painter->setIconSize(QSize(60,60));
    MainWindow *mv = new MainWindow();
    mv->show();
}

void DoctorMainView::on_calculator_clicked()
{
    ui->calculator->setIconSize(QSize(60,60));
    Widget *w = new Widget();
    w->show();
}

void DoctorMainView::on_player_clicked()
{
    ui->player->setIconSize(QSize(60,60));
    player *p = new player();
    p->show();
}

void DoctorMainView::on_logout_clicked()
{
    ui->logout->setIconSize(QSize(60,60));
    logout();
}

void DoctorMainView::on_sos_pressed()
{
    ui->sos->setIconSize(QSize(40,40));
}

void DoctorMainView::on_sos_clicked()
{
    ui->sos->setIconSize(QSize(60,60));
    cc->alarm(ID,identity);
}

void DoctorMainView::on_setting_pressed()
{
    ui->setting->setIconSize(QSize(40,40));
}

void DoctorMainView::on_setting_clicked()
{
    ui->setting->setIconSize(QSize(60,60));
}

void DoctorMainView::on_quit_pressed()
{
    ui->quit->setIconSize(QSize(40,40));
}

void DoctorMainView::on_quit_clicked()
{
    ui->quit->setIconSize(QSize(60,60));
    this->close();
}

void DoctorMainView::on_selfInfo_released()
{
    ui->selfInfo->setIconSize(QSize(60,60));
}

void DoctorMainView::on_patientInfo_released()
{
    ui->patientInfo->setIconSize(QSize(60,60));
}

void DoctorMainView::on_doctorList_released()
{
    ui->doctorList->setIconSize(QSize(60,60));
}

void DoctorMainView::on_treat_released()
{
    ui->treat->setIconSize(QSize(60,60));
}

void DoctorMainView::on_examination_released()
{
    ui->examination->setIconSize(QSize(60,60));
}

void DoctorMainView::on_canleder_released()
{
    ui->canleder->setIconSize(QSize(60,60));
}

void DoctorMainView::on_player_released()
{
    ui->player->setIconSize(QSize(60,60));
}

void DoctorMainView::on_painter_released()
{
    ui->painter->setIconSize(QSize(60,60));
}

void DoctorMainView::on_calculator_released()
{
    ui->calculator->setIconSize(QSize(60,60));
}

void DoctorMainView::on_weather_released()
{
    ui->weather->setIconSize(QSize(60,60));
}

void DoctorMainView::on_sos_released()
{
    ui->sos->setIconSize(QSize(60,60));
}

void DoctorMainView::on_setting_released()
{
    ui->setting->setIconSize(QSize(60,60));
}

void DoctorMainView::on_logout_released()
{
    ui->logout->setIconSize(QSize(60,60));
}

void DoctorMainView::on_quit_released()
{
    ui->quit->setIconSize(QSize(60,60));
}
