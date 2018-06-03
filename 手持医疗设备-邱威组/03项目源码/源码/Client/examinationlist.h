#ifndef EXAMINATIONLIST_H
#define EXAMINATIONLIST_H

#include <QWidget>
#include <electrocardiograph.h>
#include <chosepatientview.h>
namespace Ui {
class examinationList;
}

class examinationList : public QWidget
{
    Q_OBJECT
    
public:
    explicit examinationList(QWidget *parent = 0);
    ~examinationList();
    
private slots:
    void on_heartRate_pressed();

    void on_heartRate_released();

    void on_backButton_released();

    void on_temperature_released();

private:
    Ui::examinationList *ui;
};

#endif // EXAMINATIONLIST_H
