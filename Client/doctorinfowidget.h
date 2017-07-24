#ifndef DOCTORINFOWIDGET_H
#define DOCTORINFOWIDGET_H

#include <QWidget>
#include <chatclient.h>
namespace Ui {
class DoctorInfoWidget;
}

class DoctorInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DoctorInfoWidget(QWidget *parent = 0);
    ~DoctorInfoWidget();
public slots:
    void getRecord(QJsonArray);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DoctorInfoWidget *ui;
};

#endif // DOCTORINFOWIDGET_H
