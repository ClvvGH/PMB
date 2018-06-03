#ifndef WIDGET_H
#define WIDGET_H
#include <QSqlTableModel>
#include <QWidget>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <network/servercontroller.h>
#include <QSound>
namespace Ui {
class MainView;
}

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
    
private slots:
    void on_doctorButton_clicked();
    void on_PatientButton_clicked();
    void on_TreatmentButton_clicked();
    void on_examinationButton_clicked();
    void on_socketButton_clicked();
    void on_sortButton_clicked();
    void on_insertButton_clicked();
    void on_saveButton_clicked();
    void on_deleteButton_clicked();
    void on_revokeButton_clicked();
    void on_doctorQueryButton_clicked();
    void on_treatmentQueryButton_clicked();
    void on_patientQueryButton_clicked();
    void on_ExaminationQueryButton_clicked();
    void getAlarm(int,QString,int);
private:
    Ui::MainView *ui;
    QSqlTableModel *model;
    QSqlQueryModel *queryModel;
    void setItemEnable(bool);
    void setDoctorModel();
    void setPatientModel();
    void setTreatmentModel();
    void setExaminationModel();
    void setSocketModel();
    QSound *sound;
};

#endif
