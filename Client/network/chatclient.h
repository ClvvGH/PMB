#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#define HOST "127.0.0.1"
#include <QObject>
#include <QtNetwork>
#include <string>
#include <QTextCodec>
class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = 0);
    //sql语句类型
    enum requestType {EXC, QUE};
    enum returnType {SET, MSG, NONE};
signals:
    //服务器返回超时
    void returnOverTime();
    //执行失败
    void failedInExc();
    //成功返回查询结果
    void getResultSet(QList<QVariantMap*>);
    //执行成功
    void excSuccessfully();
    //发送数据超时
    void sendOverTime();
public slots:
    //读取服务器返回的json数组
    void readResultSet();
    //读取服务器返回的执行信息
    void readMessage();
    //向服务器发送sql语句
    void sendSql(QString,requestType);
    bool connectToServer();
    void disconnectFromServer();
    void readReturn();
private:
    QTcpSocket *client;
    //接收数据缓冲区
    QByteArray buffer;
    //接收数据大小
    int bufferSize;
    //返回类型
    returnType type;
    bool getSet;
    // 1成功 2失败
    int getMsg;
    QList<QVariantMap*> resultSet;
};

#endif // CHATCLIENT_H
