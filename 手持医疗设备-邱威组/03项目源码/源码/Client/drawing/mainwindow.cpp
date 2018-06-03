#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //dia init
    dia =new QFileDialog(this);



    colorpane=ui->colorpane;
    //initaite pencolor
    PenColor=QColor(0,0,0,255);
this->setWindowFlags(Qt::FramelessWindowHint);
    pix=QPixmap(240,240);
    pix.fill(Qt::white);
    //initiate points
    start=QPoint(0,0);
    end=QPoint(0,0);
    ui->setupUi(this);
    //set R G B Alphafunctions
  ui->R->setMaximum(255);
  ui->G->setMaximum(255);
  ui->B->setMaximum(255);
  ui->A->setMaximum(255);
  ui->R->setMinimum(0);
  ui->G->setMinimum(0);
  ui->B->setMinimum(0);
  ui->A->setMinimum(0);
  ui->A->setValue(255);
//set R G B Alpha initiation
  ui->R->setEnabled(false);
  ui->G->setEnabled(false);
  ui->A->setEnabled(false);
  ui->B->setEnabled(false);

  //set menubar actions slots
  this->connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(ClickOnOpen()));
  this->connect(ui->actionQuickSave,SIGNAL(triggered()),this,SLOT(ClickOnQuickSave()));
  this->connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(ClickOnSave()));
  this->connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(ClickOnAbout()));
  this->connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(ClickOnExit()));
  this->connect(ui->actionClearscreen,SIGNAL(triggered()),this,SLOT(ClickOnClearScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ClickOnOpen()
{
    dia->setWindowTitle(tr("Open Picture"));
    dia->setAcceptMode(QFileDialog::AcceptOpen);
    dia->setFileMode(QFileDialog::AnyFile);
    dia->setViewMode(QFileDialog::Detail);

    dia->setDefaultSuffix(".");
    dia->setFilter(tr("Image Files(*.jpg *.png)"));
    if(dia->exec()==QDialog::Accepted)
    {
        QString path=dia->selectedFiles()[0];
       if(pix.load(path))
            QMessageBox::information(this, tr("Information"), tr("Successfully Opened!"),QMessageBox::Ok);
       update();


    }
    ;
}
void MainWindow::ClickOnQuickSave()
{


    if( pix.save("Drawing.png"))
        QMessageBox::information(this, tr("Information"), tr("Successfully Saved!"),QMessageBox::Ok);


}
void MainWindow::ClickOnSave()
{
    dia->setWindowTitle(tr("Save Picture"));
    dia->setAcceptMode(QFileDialog::AcceptSave);
    dia->setFileMode(QFileDialog::AnyFile);
    dia->setViewMode(QFileDialog::Detail);

    dia->setDefaultSuffix(".");
    dia->setFilter(tr("Image Files(*.jpg *.png)"));
    if(dia->exec()==QDialog::Accepted)
    {
        QString path=dia->selectedFiles()[0];
        if( pix.save(path))
        {
            QMessageBox::information(this, tr("Information"), tr("Successfully Saved!"),QMessageBox::Ok);
        }

    }
}
void MainWindow::ClickOnAbout()
{
 QMessageBox::information(this, tr("Information"), tr("Easy Drawing board created by sunjunlin"),QMessageBox::Ok);


}

void MainWindow::ClickOnExit()
{
    this->close();
}
void MainWindow::ClickOnClearScreen()
{
    pix.fill(Qt::white);
    start=end=QPoint(0,0);
    update();
}

//activate buttton
void MainWindow::on_pushButton_clicked()
{
    ui->R->setEnabled(true);
    ui->G->setEnabled(true);
    ui->A->setEnabled(true);
    ui->B->setEnabled(true);


}
//choose color button
void MainWindow::on_pushButton_2_clicked()
{
    int R=ui->R->value();
    int G=ui->G->value();
    int B=ui->B->value();
    int A=ui->A->value();
    PenColor.setRed(R);
    PenColor.setGreen(G);
    PenColor.setBlue(B);
    PenColor.setAlpha(A);

    ui->colorpane->setStyleSheet(QString("background-color: rgb(%1, %2, %3,%4);").arg(R).arg(G).arg(B).arg(A));
}



void MainWindow::paintEvent(QPaintEvent *e)
{

          QPainter pp(&pix);
          pp.setRenderHint(QPainter::Antialiasing, true);
          pp.setPen(QPen(PenColor,2));
          pp.drawLine(start, end);    // 让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线
          start = end;
          QPainter painter(this);
          painter.drawPixmap(0 , 0, pix);


}
void MainWindow::mousePressEvent(QMouseEvent *e)
{

    if(e->button()==Qt::LeftButton)
    {
        start=e->pos();
    }



}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        end=e->pos();
        update();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton)
    {
        end=e->pos();
        update();
    }
}
