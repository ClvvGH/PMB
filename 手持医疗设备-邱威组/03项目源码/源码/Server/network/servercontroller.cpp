#include "servercontroller.h"

ServerController::ServerController()
{

    this->listen(QHostAddress::Any,4343);
}

ServerController::~ServerController()
{
}

void ServerController::incomingConnection(int socketDescriptor)
{
    ChatThread *ct= new ChatThread(socketDescriptor);
    connect(ct,SIGNAL(alarm(int,QString,int)),this,SLOT(getAlarm(int,QString,int)));
    ct->start();
}

void ServerController::getAlarm(int ID, QString IP,int position)
{
    emit alarm(ID,IP,position);
}
