#ifndef TREATINFOVIEW_H
#define TREATINFOVIEW_H

#include <QWidget>
#include <network/chatclient.h>
extern ChatClient *cc;
namespace Ui {
class TreatInfoView;
}

class TreatInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit TreatInfoView(int row,int PId,QWidget *parent = 0);
    ~TreatInfoView();
private slots:
    void getResult(QJsonArray);
    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_backButton_clicked();

private:
    Ui::TreatInfoView *ui;
    int row;
    int PId;
};

#endif // TREATINFOVIEW_H
