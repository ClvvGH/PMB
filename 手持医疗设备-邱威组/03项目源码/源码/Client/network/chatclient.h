#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#define HOST "192.168.1.3"
#include <QObject>
#include <QtNetwork>
#include <string>
#include <QTextCodec>
class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = 0);
    enum requestType {EXC, QUE};
    enum returnType {SET, MSG, NONE};
signals:
    void returnOverTime();
    void failedInExc();
    void getResultSet(QList<QVariantMap*>);
    void excSuccessfully();
    void sendOverTime();
public slots:
    void readResultSet();
    void readMessage();
    void sendSql(QString,requestType);
    void alarm(int,int);
    bool connectToServer();
    void disconnectFromServer();
    void readReturn();
private:
    QTcpSocket *client;
    QByteArray buffer;
    int bufferSize;
    returnType type;
    bool getSet;
    int getMsg;
    QList<QVariantMap*> resultSet;
};

#endif // CHATCLIENT_H
