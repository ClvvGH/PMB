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
    void readClient();
private:
    //sql语句类型
    enum requestType {EXC, QUE};
    //执行结果
    enum ExecResult{FAILED, SUCCESS};
    QTcpServer *server;
    QTcpSocket *socket;
    //服务端返回的json数组
    QJsonArray SJson;
    //从客户端接收的sql语句
    QJsonObject CJson;
    //存放客户端发送的sql语句
    QString sql;
    //返回sql执行成功或失败消息
    void pushMessage(ExecResult);
    //返回查询结果
    void pushData();
    //用json存放查询结果
    void jsonCoding(QSqlQuery);
    //解析客户端发送的json
    requestType jsonDiscoding();
};

#endif // CHATSERVER_H
