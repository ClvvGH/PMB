#ifndef TREATVIEW_H
#define TREATVIEW_H

#include <QWidget>
#include <QMessageBox>
#include <network/chatclient.h>
extern int ID;
extern ChatClient *cc;
namespace Ui {
class TreatView;
}

class TreatView : public QWidget
{
    Q_OBJECT

public:
    explicit TreatView(int PId, QString name, QWidget *parent = 0);
    ~TreatView();

private slots:
    void on_leftButton_clicked();
    void getErrorMessage();
    void on_rightButton_clicked();
    void getRightMessage();
    void on_backButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::TreatView *ui;
    int PId;
    QString name;
};

#endif // TREATVIEW_H
