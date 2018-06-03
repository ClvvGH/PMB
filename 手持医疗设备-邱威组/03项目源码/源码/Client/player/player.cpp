#include "player.h"
#include "ui_player.h"
#include <QUrl>
#include <QTime>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTableWidget>
#include <QStandardItem>

int n;

player::player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
//建立连接
    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    Phonon::createPath(mediaObject,audioOutput);
//控制播放/暂停按钮图标
    ui->play->setIcon(QIcon("://icon/275-play.png"));
    ui->play->setEnabled(false);
    ui->backward->setEnabled(false);
    ui->forward->setEnabled(false);

//显示时间
    connect(mediaObject,SIGNAL(tick(qint64)),this,SLOT(update(qint64)));
    connect(this,SIGNAL(showTime()),this,SLOT(update()));

//控制音量大小
    ui->volumeSlider->setAudioOutput(audioOutput);
    ui->volumeSlider->setSingleStep(5);//最小步长5/100




//设置TableWidget格式
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置边框
    ui->tableWidget->setShowGrid(false); //设置不显示格子线
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(24); //设置行距
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);//取消选中边框虚线


//扫描本地文件
    QDir dir("/usr/local/music/");
    playList << "*.mp3";
    dir.setNameFilters(playList);
    list = dir.entryInfoList();
    if(list.length() != 0){
        for(int i = 0;i < list.size();++i){

            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item->setText(list.at(i).fileName());
            ui->tableWidget->setItem(i,0,item);
        }
    }

//播放结束下一曲
    connect(mediaObject, SIGNAL(finished()), SLOT(finished()));//循环播放

}

player::~player()
{
    delete ui;
}

//计算歌曲时间
void player::update(qint64 time){
    qint64 totalTime = mediaObject->totalTime();
    QTime displayTime_1(0,(time/60000)%60,(time/1000)%60);
    QTime displayTime_2(0,(totalTime/60000)%60,(totalTime/1000)%60);
    ui->time_1->setText(displayTime_1.toString("mm:ss")+"/"+displayTime_2.toString("mm:ss"));
    ui->time_1->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
}

//播放/暂停
void player::on_play_clicked()
{
    ui->seekSlider->setMediaObject(mediaObject);

    emit showTime();

    if(mediaObject->state() == Phonon::PlayingState){
        ui->play->setIcon(QIcon("://icon/275-play.png"));
        mediaObject->pause();
    }else{
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        mediaObject->play();
    }


}


//双击列表播放
void player::on_tableWidget_doubleClicked(const QModelIndex &index)
{

    ui->seekSlider->setMediaObject(mediaObject);
    int row = ui->tableWidget->currentItem()->row();
    n = row;
    songsPath = "/usr/local/music/"+list.at(n).fileName();


    QUrl url(songsPath);
    mediaObject->setCurrentSource(url);
    mediaObject->play();

    ui->play->setIcon(QIcon("://icon/280-pauze.png"));
    ui->songName->setText(list.at(n).fileName());
    ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    ui->play->setEnabled(true);
    ui->backward->setEnabled(true);
    ui->forward->setEnabled(true);
}

//上一首
void player::on_backward_clicked()
{
    ui->seekSlider->setMediaObject(mediaObject);

    if (n == 0){
        mediaObject->stop();
        n = list.size()-1;
        songsPath = ""+list.at(n).fileName();

        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }else{
        mediaObject->stop();
        --n;
        songsPath = "/usr/local/music/"+list.at(n).fileName();
        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }

}

//下一首
void player::on_forward_clicked()
{
    ui->seekSlider->setMediaObject(mediaObject);

    if(n == list.size()-1){
        mediaObject->stop();
        n = 0;
        songsPath = "/usr/local/music/"+list.at(n).fileName();

        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }else{
        mediaObject->stop();
        ++n;
        songsPath = "/usr/local/music/"+list.at(n).fileName();
        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }

}

//播放结束后下一曲
void player::finished(){
    ui->seekSlider->setMediaObject(mediaObject);

    if(n == list.size()-1){
        n = 0;
        songsPath = "/usr/local/music/"+list.at(n).fileName();

        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }else{
        ++n;
        songsPath = "/usr/local/music/"+list.at(n).fileName();
        QUrl url(songsPath);
        mediaObject->setCurrentSource(url);
        mediaObject->play();
        ui->play->setIcon(QIcon("://icon/280-pauze.png"));
        ui->songName->setText(list.at(n).fileName());
        ui->songName->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->tableWidget->selectRow(n);
    }
}



void player::on_pushButton_2_clicked()
{
    this->close();
}
