#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTime>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

     QString  mp,temp,np;
     int flag3,count ;
     double num,FIRST,SECOND,RESULT;
     char flag;
     QString flag1,flag2,str,strr;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_time_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_subtract_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_clean_clicked();

    void on_pushButton_Add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_SCIENCE_clicked();

    void on_pushButton_JINZHI_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
