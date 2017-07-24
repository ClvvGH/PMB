#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QToolButton>
#include <QSqlTableModel>
#include <QDialog>
#include <QStackedWidget>


namespace Ui {
class SearchView;
}

class SearchView : public QDialog
{
    Q_OBJECT
    
public:
    explicit SearchView(QWidget *parent = 0);
    ~SearchView();

    

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_DoctortoolButton_clicked();

    void on_PatienttoolButton_clicked();

    void on_ExaminationtoolButton_clicked();

    void on_TreatmenttoolButton_clicked();

private:
    Ui::SearchView *ui;
    QSqlTableModel *model;
};

#endif
