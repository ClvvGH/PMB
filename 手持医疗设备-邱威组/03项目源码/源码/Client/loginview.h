#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <doctorregisterview.h>
#include <patientregisterview.h>
#include <network/chatclient.h>
#include <QMessageBox>
#include <doctormainview.h>
#include <patientmainview.h>
extern ChatClient *cc;
extern int identity;
extern int ID;
namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = 0);
    ~LoginView();
signals:
    void passwordCorrect();
    void passwordWrong();
private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();
    void on_RegisterButton_clicked();
    void on_DoctorButton_clicked();
    void on_PatientButton_clicked();
    void getResult(QList<QVariantMap*>);
    void login();
    void sendWrongMessage();
private:
    Ui::LoginView *ui;
    void setItemEnable(bool);

};

#endif // LOGINVIEW_H
