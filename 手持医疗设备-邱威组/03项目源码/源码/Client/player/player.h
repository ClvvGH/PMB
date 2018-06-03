#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <phonon>
#include <QTableWidget>
#include <QFileInfoList>


namespace Ui {
class player;
}

class player : public QWidget
{
    Q_OBJECT
    
public:
    explicit player(QWidget *parent = 0);
    ~player();
    
private slots:

    void update(qint64 time);

    void on_play_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_backward_clicked();

    void on_forward_clicked();

    void finished();

    void on_pushButton_2_clicked();

signals:

    void showTime();

private:
    Ui::player *ui;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;

    QStringList playList;
    QFileInfoList list;

    QString songsPath;

};

#endif // PLAYER_H
