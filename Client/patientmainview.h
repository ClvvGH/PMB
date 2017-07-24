#ifndef PATIENTMAINVIEW_H
#define PATIENTMAINVIEW_H

#include <QWidget>
#include <selfinfoview.h>
#include <treatlistview.h>
#include <doctorlistview.h>
#include <loginview.h>
extern int ID;
extern int identity;
namespace Ui {
class PatientMainView;
}

class PatientMainView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientMainView(QWidget *parent = 0);
    ~PatientMainView();

private slots:
    void logout();

    void on_selfInfo_clicked();

    void on_doctorlist_clicked();

    void on_treatment_clicked();

private:
    Ui::PatientMainView *ui;
};

#endif // PATIENTMAINVIEW_H
