#ifndef DOCTORREGISTERVIEW_H
#define DOCTORREGISTERVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QMessageBox>
extern ChatClient *cc;
namespace Ui {
class DoctorRegisterView;
}

class DoctorRegisterView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorRegisterView(QWidget *parent = 0);
    ~DoctorRegisterView();
signals:
    void accessibleUsername();
    void usernameExist();
private:
    Ui::DoctorRegisterView *ui;


private slots:
    void on_confirm_clicked();
    void on_password_editingFinished();
    void on_sex_activated(int index);
    void on_office_activated(int index);
    void on_confirm_password_editingFinished();
    void on_name_editingFinished();
    void on_position_activated(int index);
    void on_phoneNo_editingFinished();
    void on_username_editingFinished();
    void on_bornYear_editingFinished();
    void registerSuccessfully();
    void registerFailed();
    void on_cancel_clicked();
    void doRegister();
    void sendMessage();
    void getResult(QList<QVariantMap*>);

};
#endif // DOCTORREGISTERVIEW_H
