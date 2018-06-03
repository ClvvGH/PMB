#ifndef SECURITYINFOVIEW_H
#define SECURITYINFOVIEW_H

#include <QWidget>
#include <changepasswordview.h>
#include <network/chatclient.h>
extern int ID;
extern int identity;
extern ChatClient *cc;
namespace Ui {
class SecurityInfoView;
}

class SecurityInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit SecurityInfoView(QWidget *parent = 0);
    ~SecurityInfoView();

private slots:
    void on_pushButton_clicked();
    void getResult(QList<QVariantMap*>);
    void on_backButton_clicked();

private:
    Ui::SecurityInfoView *ui;
};

#endif // SECURITYINFOVIEW_H
