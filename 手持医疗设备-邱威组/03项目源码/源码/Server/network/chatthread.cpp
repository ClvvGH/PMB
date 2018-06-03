#include "chatthread.h"

ChatThread::ChatThread(int socketDescriptor, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
}

void ChatThread::run()
{
    ChatServer * cs = new ChatServer(socketDescriptor);
    connect(cs,SIGNAL(alarm(int,QString,int)),this,SLOT(getAlarm(int,QString,int)));
    exec();
}

void ChatThread::getAlarm(int ID, QString IP,int position)
{
    emit alarm(ID,IP,position);
}
