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
    ct->start();
}
