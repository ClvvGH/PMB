#ifndef SCEINCE_H
#define SCEINCE_H

#include <QMainWindow>

namespace Ui {
class SCEINCE;
}

class SCEINCE : public QMainWindow
{
    Q_OBJECT

public:
    explicit SCEINCE(QWidget *parent = 0);
    ~SCEINCE();

private:
    Ui::SCEINCE *ui;
};

#endif // SCEINCE_H
