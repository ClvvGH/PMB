#ifndef SCIENCE_H
#define SCIENCE_H

#include <QWidget>
#include<qmath.h>
namespace Ui {
class SCIENCE;
}

class SCIENCE : public QWidget
{
    Q_OBJECT

public:
    explicit SCIENCE(QWidget *parent = 0);
    ~SCIENCE();
    QString  TEMP;
    int FLAG;
    QString jieguo;
    double result,num,FIRST,SECOND;



private slots:
    void on_pushButton_pingfang_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_lifang_clicked();

    void on_pushButton_zhishu_clicked();

    void on_pushButton_jiecheng_clicked();

    void on_pushButton_daoshu_clicked();

    void on_pushButton_yuxian_clicked();

    void on_pushButton_zhengqie_clicked();

    void on_pushButton_zhengxian_clicked();

    void on_pushButton_EQUAL_clicked();

    void on_pushButton_clean_clicked();

    void on_pushButton_POINT_clicked();

    void on_pushButton_GEN_clicked();

private:
    Ui::SCIENCE *ui;
};

#endif // SCIENCE_H
