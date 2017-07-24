#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) :
    QObject(parent)
{
    bufferSize =0;
    getSet = false;
    getMsg = 0;
    client = new QTcpSocket();
    //建立连接以后，服务器若是有返回消息会自动调用readyRead()信号
    connect(client, SIGNAL(readyRead()), this, SLOT(readReturn()));
}
void ChatClient::sendSql(QString sql, ChatClient::requestType type)
{
    CJson.insert("sql",sql);
    qDebug() << "sql:" +sql;
    QByteArray arr;
    if (type == EXC )
    {
        //向服务器发送非查询类sql
        CJson.insert("type","execute");
        QJsonDocument *doc = new QJsonDocument(CJson);
        arr = doc->toBinaryData();
        qDebug() << "Binary set size to send:";
        qDebug() << arr.size();
        arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
        arr.insert(4,QString("0"));
        client->write(arr);
        if (!client->waitForBytesWritten(3000))
        {
            //向服务器发送数据超时
            qDebug() << "failed in sending sql ";
            emit sendOverTime();
        }
        else
        {
            qDebug() << "send sql successfully";
        }
        if (!client->waitForReadyRead(3000))
        {
            qDebug() << "timing out in getting result";
            emit returnOverTime();
        }
        else
        {
            //返回成功
            qDebug() << "get message successfully";
        }
    }
    else
    {
        CJson.insert("type","query");
        QJsonDocument *doc = new QJsonDocument(CJson);
        arr = doc->toBinaryData();
        qDebug() << "Binary set size to send:";
        qDebug() << arr.size();
        arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
        arr.insert(4,QString("0"));
        client->write(arr);
        qDebug() << "sending sql statment to host";
        if (!client->waitForBytesWritten(3000))
        {
            qDebug() << "failed in sending sql ";

            emit sendOverTime();
        }
        else
        {
            qDebug() << "send sql successfully";
        }
        if (!client->waitForReadyRead(3000))
        {
            qDebug() << "timing out in getting result";
            emit returnOverTime();
        }
        else
        {
            qDebug() << "get result set successfully";
        }
    }
    if(getSet)
    {
        emit getResultSet(SJson);
        getSet =false;
    }
    if(getMsg ==1)
    {
        emit excSuccessfully();
        getMsg = 0;
    }
    else if(getMsg ==2)
    {
        emit failedInExc();
        getMsg = 0;
    }
}

void ChatClient::readReturn()
{
    buffer.append(client->readAll());
    if(bufferSize == 0)
    {
        QString strSize = QString(buffer.at(0))+QString(buffer.at(1))+QString(buffer.at(2))+QString(buffer.at(3));
        bufferSize =strSize.toInt(0,16);
        type =(returnType)QString(buffer.at(4)).toInt();
        buffer.remove(0,5);
    }
    //判断数据是否读取完整
    if(bufferSize<=buffer.size())
    {
        if (type == MSG)
        {
            readMessage();
        }
        else if (type == SET)
        {
            readResultSet();
        }
        else
        {
            qDebug() << "return type error";
        }
    }
}

void ChatClient::readResultSet()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(buffer);
    buffer.clear();
    bufferSize =0;
    SJson = doc.array();
    getSet = true;
}

void ChatClient::readMessage()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(buffer);
    buffer.clear();
    bufferSize = 0;
    QJsonObject json = doc.object();
    QString result= json.take("result").toString();
    if (!QString::compare(result,"success"))
    {
        qDebug() << "sql statment execute successfully";
        getMsg = 1;
    }
    else
    {
        qDebug() << "failed in executing";
        getMsg =2;
    }
}

bool ChatClient::connectToServer()
{
    client->connectToHost(QHostAddress(HOST),4343);
    if (client->waitForConnected())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ChatClient::disconnectFromServer()
{
    client->disconnectFromHost();
}
