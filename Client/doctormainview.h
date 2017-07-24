#ifndef DOCTORMAINVIEW_H
#define DOCTORMAINVIEW_H

#include <QWidget>
#include <selfinfoview.h>
#include <loginview.h>
#include <doctorlistview.h>
#include <patientlistview.h>
#include <chosepatientview.h>
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
    void on_pushButton_clicked();
    void logout();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DoctorMainView *ui;
};

#endif // DOCTORMAINVIEW_H
