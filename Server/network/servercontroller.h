#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <QObject>
#include <QtNetwork>
#include <QList>
#include <QTcpServer>
#include <network/chatthread.h>
class ServerController: public QTcpServer
{
    Q_OBJECT
public:
    ServerController();
    ~ServerController();
private:
    //
    QList<QTcpSocket*>clients;
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVERCONTROLLER_H
