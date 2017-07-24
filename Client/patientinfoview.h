#ifndef PATIENTINFOVIEW_H
#define PATIENTINFOVIEW_H

#include <QWidget>
#include <QDebug>
#include <network/chatclient.h>
#include <QJsonArray>
#include <QMessageBox>
#include <treatview.h>
#include <treatlistview.h>
extern ChatClient *cc;
namespace Ui {
class PatientInfoView;
}

class PatientInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientInfoView(int Pid, QWidget *parent = 0);
    explicit PatientInfoView(QWidget *parent = 0);
    ~PatientInfoView();

private slots:
    void on_backButton_clicked();
    void getResult(QJsonArray);
    void on_treat_clicked();

    void on_treatMentButton_clicked();

private:
    Ui::PatientInfoView *ui;
    int PId;
    QString name;
};

#endif // PATIENTINFOVIEW_H
