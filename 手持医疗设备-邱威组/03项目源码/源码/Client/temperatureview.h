#ifndef TEMPERATUREVIEW_H
#define TEMPERATUREVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QDate>
#include <QMessageBox>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
extern ChatClient *cc;
extern int ID;
namespace Ui {
class TemperatureView;
}

class TemperatureView : public QWidget
{
    Q_OBJECT
    
public:
    explicit TemperatureView(int PId,QString name, QWidget *parent = 0);
    ~TemperatureView();
    
private slots:
    void on_checkButton_released();
    void Success();
    void failed();
    void on_saveButton_released();

    void on_backButton_released();

private:
    Ui::TemperatureView *ui;
    int PId;
    QString name;
};

#endif // TEMPERATUREVIEW_H
