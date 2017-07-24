#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QObject>
#include <QtNetwork>
#include <QJsonObject>
#include <database.h>
#include <QTextStream>

class ChatServer : public QObject
{
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = 0);
signals:
    void newConnection();
public slots:
    void acceptConnection();
    void readFromClient();
    void acceptError(QAbstractSocket::SocketError);
private:
    //sql语句类型
    enum requestType {EXC, QUE};
    //执行结果
    enum ExecResult{FAILED, SUCCESS};
    QTcpServer *server;
    QTcpSocket *socket;
    //接收缓冲区
    QByteArray buffer;
    //通信数据大小
    int bufferSize;
    //从客户端接收的sql语句
    QJsonObject CJson;
    //存放客户端发送的sql语句
    QString sql;
    //返回sql执行成功或失败消息
    void pushMessage(ExecResult);
    //返回查询结果
    void pushData(QJsonArray);
    //用json存放查询结果
    QJsonArray jsonCoding(QSqlQuery);
    //解析客户端发送的json
    requestType jsonDiscoding();
    //记录客户端的ip、操作和操作时间
    void recordClientAction(QString);
    void readComplete();
};

#endif // CHATSERVER_H
