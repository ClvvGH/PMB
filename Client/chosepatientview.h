#ifndef CHOSEPATIENTVIEW_H
#define CHOSEPATIENTVIEW_H

#include <QWidget>
#include <network/chatclient.h>
#include <QStandardItem>
#include <QMessageBox>
#include <treatview.h>
extern ChatClient *cc;
namespace Ui {
class ChosePatientView;
}

class ChosePatientView : public QWidget
{
    Q_OBJECT

public:
    explicit ChosePatientView(QWidget *parent = 0);
    ~ChosePatientView();

private slots:
    void on_queryButton_clicked();
    void getResult(QList<QVariantMap*>);

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_backButton_clicked();

private:
    Ui::ChosePatientView *ui;
};

#endif // ChosePatientView_H
