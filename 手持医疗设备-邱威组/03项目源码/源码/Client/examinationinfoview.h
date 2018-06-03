#ifndef EXAMINATIONINFOVIEW_H
#define EXAMINATIONINFOVIEW_H

#include <QWidget>
#include <network/chatclient.h>
extern ChatClient *cc;
namespace Ui {
class ExaminationInfoView;
}

class ExaminationInfoView : public QWidget
{
    Q_OBJECT
    
public:
    explicit ExaminationInfoView(int PId, QWidget *parent = 0);
    ~ExaminationInfoView();
private slots:
    void getResult(QList<QVariantMap*>);
    void on_backButton_clicked();

private:
    Ui::ExaminationInfoView *ui;
    int PId;
};

#endif // EXAMINATIONINFOVIEW_H
