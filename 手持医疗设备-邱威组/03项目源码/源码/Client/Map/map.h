#ifndef MAP_H
#define MAP_H

#include <QWidget>

namespace Ui {
class map;
}

class map : public QWidget
{
    Q_OBJECT
    
public:
    explicit map(QWidget *parent = 0);
    ~map();
    
private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::map *ui;
};

#endif // MAP_H
