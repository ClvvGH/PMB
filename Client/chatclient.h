#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#define HOST "10.10.32.70"
#include <QObject>
#include <QtNetwork>
#include <string>
#include <QJsonObject>
#include <QJsonArray>
class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = 0);
    //sql语句类型
    enum requestType {EXC, QUE};
signals:
    //服务器返回超时
    void returnOverTime();
    //执行失败
    void failedInExc();
    //成功返回查询结果
    void getResultSet(QJsonArray);
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
private:
    QTcpSocket *client;
    //客户端json
    QJsonObject CJson;
    //服务器json
    QJsonArray SJson;
};

#endif // CHATCLIENT_H
