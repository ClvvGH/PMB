#ifndef PATIENTLISTVIEW_H
#define PATIENTLISTVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QStandardItem>
#include <QMessageBox>
#include <patientinfoview.h>
extern ChatClient *cc;
namespace Ui {
class PatientListView;
}

class PatientListView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientListView(QWidget *parent = 0);
    ~PatientListView();

private slots:
    void on_queryButton_clicked();
    void getResult(QList<QVariantMap*>);

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_backButton_clicked();

private:
    Ui::PatientListView *ui;
};

#endif // PATIENTLISTVIEW_H
