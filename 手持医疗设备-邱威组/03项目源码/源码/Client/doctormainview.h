#ifndef DOCTORMAINVIEW_H
#define DOCTORMAINVIEW_H

#include <QWidget>
#include <selfinfoview.h>
#include <loginview.h>
#include <doctorlistview.h>
#include <patientlistview.h>
#include <chosepatientview.h>
#include <QMouseEvent>
#include <QThread>
#include <QTimer>
#include <examinationlist.h>
#include <QDateTime>
#include <player/player.h>
#include <caculator/widget.h>
#include <drawing/mainwindow.h>
#include <Map/map.h>
extern int ID;
extern int identity;

namespace Ui {
class DoctorMainView;
}

class DoctorMainView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorMainView(QWidget *parent = 0);
    ~DoctorMainView();

private slots:
    void logout();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void move();
    void on_selfInfo_pressed();
    void on_selfInfo_clicked();
    void on_calculator_pressed();
    void on_doctorList_pressed();
    void on_patientInfo_pressed();
    void on_treat_pressed();
    void on_examination_pressed();
    void on_canleder_pressed();
    void on_weather_pressed();
    void on_painter_pressed();
    void on_player_pressed();
    void on_logout_pressed();
    void on_patientInfo_clicked();
    void on_doctorList_clicked();
    void on_treat_clicked();
    void on_examination_clicked();
    void on_canleder_clicked();
    void on_weather_clicked();
    void on_painter_clicked();
    void on_calculator_clicked();
    void on_player_clicked();
    void on_logout_clicked();
    void on_sos_pressed();
    void on_sos_clicked();
    void showTime();
    void on_setting_pressed();
    void on_setting_clicked();
    void on_quit_pressed();
    void on_quit_clicked();
    void on_selfInfo_released();
    void on_patientInfo_released();
    void on_doctorList_released();
    void on_treat_released();
    void on_examination_released();
    void on_canleder_released();
    void on_player_released();
    void on_painter_released();
    void on_calculator_released();
    void on_weather_released();
    void on_sos_released();
    void on_setting_released();
    void on_logout_released();
    void on_quit_released();

private:
    QPoint startPoint;
    QPoint nowPoint;
    QPoint rPoint;
    Ui::DoctorMainView *ui;
    QTimer *timer;
    int moveX;
    int page;
    void setPageLogo();
};

#endif // DOCTORMAINVIEW_H
