#include "chatthread.h"

ChatThread::ChatThread(int socketDescriptor, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
}

void ChatThread::run()
{
    ChatServer * cs = new ChatServer(socketDescriptor);
    exec();
}
