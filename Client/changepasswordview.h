#ifndef CHANGEPASSWORDVIEW_H
#define CHANGEPASSWORDVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QMessageBox>
extern int ID;
extern int identity;
extern ChatClient *cc;
namespace Ui {
class ChangePasswordView;
}

class ChangePasswordView : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePasswordView(QWidget *parent = 0);
    ~ChangePasswordView();

private slots:
    void on_pushButton_clicked();
    void getErrorMessage();
    void getRightMessage();
    void checkPassword(QList<QVariantMap*>);
    void passwordError();
    void on_pushButton_2_clicked();

private:
    Ui::ChangePasswordView *ui;
};

#endif // CHANGEPASSWORDVIEW_H
