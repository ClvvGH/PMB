#ifndef PATIENTREGISTERVIEW_H
#define PATIENTREGISTERVIEW_H

#include <QDialog>
#include <network/chatclient.h>
#include <QMessageBox>
extern ChatClient *cc;
extern int ID;
extern int identity;
namespace Ui {
class PatientRegisterView;
}

class PatientRegisterView : public QDialog
{
    Q_OBJECT

public:
    explicit PatientRegisterView(QWidget *parent = 0);
    ~PatientRegisterView();

private slots:
    void on_confirm_clicked();
    void getResult(QList<QVariantMap*>);
    void getErrorMessage();
    void getRightMessage();

private:
    Ui::PatientRegisterView *ui;
};

#endif // PATIENTREGISTERVIEW_H
