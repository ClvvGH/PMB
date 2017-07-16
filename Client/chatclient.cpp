#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) :
    QObject(parent)
{
    client = new QTcpSocket();
    //建立连接以后，服务器若是有返回消息会自动调用readyRead()信号
    //connect(client, SIGNAL(readyRead()), this, SLOT(readReturn()));
}
void ChatClient::sendSql(QString sql, ChatClient::requestType type)
{
    CJson.insert("sql",sql);
    QByteArray arr;
    if (type == EXC )
    {
        //向服务器发送非查询类sql
        CJson.insert("type","execute");
        QJsonDocument *doc = new QJsonDocument(CJson);
        arr = doc->toBinaryData();
        client->write(arr);
        if (!client->waitForBytesWritten(30000))
        {
            //向服务器发送数据超时
            qDebug() << "发送数据超时";
            emit sendOverTime();
        }
        else
        {
            qDebug() << "发送数据成功";
        }
        connect(client, SIGNAL(readyRead()), this, SLOT(readMessage()));
        if (!client->waitForReadyRead(30000))
        {
            //服务器返回超时（30s）
            qDebug() << "服务器返回超时";
            //发送返回超时信息
            emit returnOverTime();
        }
        else
        {
            //返回成功
            qDebug() << "服务器返回成功";
        }
    }
    else
    {
        CJson.insert("type","query");
        QJsonDocument *doc = new QJsonDocument(CJson);
        arr = doc->toBinaryData();
        client->write(arr);
        if (!client->waitForBytesWritten(30000))
        {
            //向服务器发送数据超时
            qDebug() << "发送数据超时";
            emit sendOverTime();
        }
        else
        {
            qDebug() << "发送数据成功";
        }
        connect(client, SIGNAL(readyRead()), this, SLOT(readResultSet()));
        if (!client->waitForReadyRead(30000))
        {
            //服务器超时
            qDebug() << "服务器返回超时";
            emit returnOverTime();
        }
        else
        {
            qDebug() << "服务器返回成功";
        }
    }
}



void ChatClient::readResultSet()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(client->readAll());
    SJson = doc.array();
    emit getResultSet(SJson);
}
void ChatClient::readMessage()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(client->readAll());
    QJsonObject json = doc.object();
    if (QString::compare(json.take("result").toString(),"success"))
    {
        qDebug() << "sql statment execute successfully";
        emit excSuccessfully();
    }
    else
    {
        qDebug() << "failed in executing";
        emit failedInExc();
    }
}

bool ChatClient::connectToServer()
{
    client->connectToHost(QHostAddress(HOST),6666);
    if (client->waitForConnected())
    {
        return true;
    }
    else
    {
        return false;
    }
}
