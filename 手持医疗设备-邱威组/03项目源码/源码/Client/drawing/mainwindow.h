#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPixmap>
#include<QPainter>
#include<QFileDialog>
#include<QMessageBox>
#include<QMouseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void ClickOnOpen();
    void ClickOnQuickSave();
    void ClickOnSave();
    void ClickOnAbout();
    void ClickOnExit();
    void ClickOnClearScreen();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QColor PenColor;
    Ui::MainWindow *ui;
    QPoint start;
    QPoint end;
    QPixmap pix;
    QPainter pp;
    QWidget *colorpane;
    QFileDialog *dia;
protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};
#endif // MAINWINDOW_H
