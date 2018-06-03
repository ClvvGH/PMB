#ifndef ELECTROCARDIOGRAPH_H
#define ELECTROCARDIOGRAPH_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QDateTime>
namespace Ui {
class Electrocardiograph;
}

class Electrocardiograph : public QWidget
{
    Q_OBJECT
    
public:
    explicit Electrocardiograph(QWidget *parent = 0);
    ~Electrocardiograph();
private:
    Ui::Electrocardiograph *ui;
    QPoint lastPoint;
    QPoint penultimatePoint;
    QPixmap *pixmap;
    QTimer *timer;
protected:
    void paintEvent(QPaintEvent *);
private slots:

    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_2_released();
};

#endif // ELECTROCARDIOGRAPH_H
