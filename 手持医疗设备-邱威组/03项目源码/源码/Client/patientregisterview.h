#ifndef PATIENTREGISTERVIEW_H
#define PATIENTREGISTERVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QMessageBox>
extern ChatClient *cc;
extern int ID;
extern int identity;
namespace Ui {
class PatientRegisterView;
}

class PatientRegisterView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientRegisterView(QWidget *parent = 0);
    ~PatientRegisterView();

private slots:
    void getResult(QList<QVariantMap*>);
    void getErrorMessage();
    void getRightMessage();
    void on_confirm_released();

    void on_cancel_released();

    void on_username_editingFinished();

    void on_password_editingFinished();

    void on_confirm_password_editingFinished();

    void on_name_editingFinished();

    void on_bornYear_editingFinished();

    void on_phoneNo_editingFinished();

private:
    Ui::PatientRegisterView *ui;
};

#endif // PATIENTREGISTERVIEW_H
