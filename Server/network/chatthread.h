#ifndef CHATTHREAD_H
#define CHATTHREAD_H

#include <QThread>
#include <network/chatserver.h>
class ChatThread : public QThread
{
    Q_OBJECT
public:
    explicit ChatThread(int socketDescriptor, QObject *parent = 0);
    
signals:
    
public slots:
private:
    int socketDescriptor;
protected:
    void run();
};

#endif // CHATTHREAD_H
