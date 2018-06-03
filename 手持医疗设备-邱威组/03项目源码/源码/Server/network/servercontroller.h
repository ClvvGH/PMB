#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <QObject>
#include <QtNetwork>
#include <QList>
#include <QTcpServer>
#include <network/chatthread.h>
#include <QMessageBox>
#include <database/database.h>
#include <QSound>
class ServerController: public QTcpServer
{
    Q_OBJECT
public:
    ServerController();
    ~ServerController();
private:
    QList<QTcpSocket*>clients;
signals:
    void alarm(int ID,QString IP,int position);
private slots:
    void getAlarm(int ID,QString IP,int position);
protected:
    void incomingConnection(int socketDescriptor);

};

#endif // SERVERCONTROLLER_H
