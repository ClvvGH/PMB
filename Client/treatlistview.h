#ifndef TREATLISTVIEW_H
#define TREATLISTVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QJsonArray>
#include <treatinfoview.h>
extern ChatClient *cc;
namespace Ui {
class TreatListView;
}

class TreatListView : public QWidget
{
    Q_OBJECT

public:
    explicit TreatListView(int PId,QWidget *parent = 0);
    ~TreatListView();

private slots:
    void on_backButton_clicked();
    void getResult(QJsonArray);

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::TreatListView *ui;
    int PId;
};

#endif // TREATLISTVIEW_H
