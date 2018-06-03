#ifndef DOCTORLISTVIEW_H
#define DOCTORLISTVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QTableWidgetItem>
#include <QStandardItem>
extern ChatClient *cc;
namespace Ui {
class DoctorListView;
}

class DoctorListView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorListView(QWidget *parent = 0);
    ~DoctorListView();
private slots:
        void getAndSetResult(QList<QVariantMap*>);
        void on_pushButton_clicked();

private:
    Ui::DoctorListView *ui;

};

#endif // DOCTORLISTVIEW_H
