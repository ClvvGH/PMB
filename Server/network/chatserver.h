#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QtNetwork>
#include <database/database.h>
#include <QTextStream>

class ChatServer : public QObject
{
    Q_OBJECT
public:
    explicit ChatServer(int socketDescriptor, QObject *parent = 0);
    //请求类型
    enum requestType {EXC, QUE, NONE};
    ~ChatServer();
private slots:
    void readFromClient();
private:
    //执行结果
    enum ExecResult{FAILED, SUCCESS};
    //客户端连接
    QTcpSocket *client;
    //接收缓冲区
    QByteArray buffer;
    //从客户端接收的请求类型
    requestType type;
    //通信数据大小
    int bufferSize;
    //存放从客户端接收的sql语句
    QString sql;
    //返回sql执行成功或失败消息
    void pushMessage(ExecResult);
    //返回查询结果
    void pushData(QSqlQuery);
    //从缓存区得到sql语句
    void getSql();
    //记录客户端的ip、操作和操作时间
    void recordClientAction(QString);
    void readComplete();
};

#endif // CHATSERVER_H
