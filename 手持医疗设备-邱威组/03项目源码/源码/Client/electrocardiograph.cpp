#include "electrocardiograph.h"
#include "ui_electrocardiograph.h"

Electrocardiograph::Electrocardiograph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Electrocardiograph)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    lastPoint = QPoint(-1,0);
    penultimatePoint = QPoint(-1,0);
    ui->setupUi(this);
    pixmap = new QPixmap("://resource/pc2.png");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(20);
}

Electrocardiograph::~Electrocardiograph()
{
    delete ui;
}

void Electrocardiograph::paintEvent(QPaintEvent *event)
{
    int value = (ui->horizontalSlider->value()*145)/100;
    QPainter painter(pixmap);
    if(lastPoint.x()>=262)
    {
        penultimatePoint.setX(lastPoint.x());
        penultimatePoint.setY(lastPoint.y());
        lastPoint.setX(0);
        lastPoint.setY(value);
        painter.end();
        painter.begin(this);
        painter.drawPixmap(-80,-40,511,351,*pixmap);
        painter.end();
    }
    else if (lastPoint.x()==-1)
    {
        painter.end();
        //绘制背景
        painter.begin(this);
        painter.drawPixmap(-80,-40,511,351,*pixmap);
        lastPoint.setX(0);
        lastPoint.setY(value);
        painter.end();
    }
    else if (penultimatePoint.x()==-1 || penultimatePoint.x()>=262)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient lg(lastPoint.x()+125,80,lastPoint.x()+125,145+80);
        lg.setColorAt(0,Qt::black);
        lg.setColorAt(0.5,Qt::green);
        lg.setColorAt(0.25,Qt::green);
        lg.setColorAt(0.75,Qt::green);
        lg.setColorAt(1,Qt::black);
        //painter.setBrush(QColor(255,255,255));
        //painter.setBrush(Qt::SolidPattern);
        painter.setBrush(QBrush(lg));
        painter.drawRect(lastPoint.x()+125,+80,1,145);
        painter.setPen(QPen(QColor(0,0,0,200),1));
        painter.drawLine(QPointF(lastPoint.x()+125,lastPoint.y()+80),QPointF(lastPoint.x()+1+125,value+80));
        penultimatePoint.setX(lastPoint.x());
        penultimatePoint.setY(lastPoint.y());
        lastPoint.setX(lastPoint.x()+1);
        lastPoint.setY(value);
        painter.end();
        painter.begin(this);
        painter.drawPixmap(-80,-40,511,351,*pixmap);
        painter.end();
    }
    else
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient lg(lastPoint.x()+125,80,lastPoint.x()+125,145+80);
        lg.setColorAt(0,Qt::black);
        lg.setColorAt(0.5,Qt::green);
        lg.setColorAt(0.25,Qt::green);
        lg.setColorAt(0.75,Qt::green);
        lg.setColorAt(1,Qt::black);
        //painter.setBrush(QColor(255,255,255));
        //painter.setBrush(Qt::SolidPattern);
        painter.setBrush(QBrush(lg));
        painter.drawRect(lastPoint.x()+125,80,1,145);
        painter.setPen(QPen(QColor(0,255,0,180),1));
        painter.drawLine(QPointF(lastPoint.x()+125,lastPoint.y()+80),QPointF(penultimatePoint.x()+125,penultimatePoint.y()+80));
        painter.setPen(QPen(QColor(0,0,0,200),1));
        painter.drawLine(QPointF(lastPoint.x()+125,lastPoint.y()+80),QPointF(lastPoint.x()+1+125,value+80));
        penultimatePoint.setX(lastPoint.x());
        penultimatePoint.setY(lastPoint.y());
        lastPoint.setX(lastPoint.x()+1);
        lastPoint.setY(value);
        painter.end();
        painter.begin(this);
        painter.drawPixmap(-80,-40,511,351,*pixmap);
        painter.end();
    }
}


void Electrocardiograph::on_pushButton_pressed()
{

}

void Electrocardiograph::on_pushButton_released()
{
    timer->stop();
    this->close();
}

void Electrocardiograph::on_pushButton_2_released()
{
    timer->start(20);
}
