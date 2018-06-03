#ifndef SELFINFOVIEW_H
#define SELFINFOVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <securityinfoview.h>
#include <QMessageBox>

extern int ID;
extern int identity;
extern ChatClient *cc;

namespace Ui {
class SelfInfoView;
}


class SelfInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit SelfInfoView(QWidget *parent = 0);
    ~SelfInfoView();
signals:
    void logout();
private slots:
    void getAndShowResult(QList<QVariantMap*>);
    void getRightMessage();
    void getErrorMessage();
    void on_backButton_clicked();

    void on_logoutButton_clicked();

    void on_securityButton_clicked();

    void on_editInfoButton_clicked();

private:
    Ui::SelfInfoView *ui;
    void showInfo();

};

#endif // SELFINFOVIEW_H
