#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) :
    QObject(parent)
{
    buffer.clear();
    bufferSize =0;
    resultSet.clear();
    type = NONE;
    getMsg =0;
    getSet = false;
    client = new QTcpSocket();
    //建立连接以后，服务器若是有返回消息会自动调用readyRead()信号
    connect(client, SIGNAL(readyRead()), this, SLOT(readReturn()));
}
void ChatClient::sendSql(QString sql, ChatClient::requestType type)
{
    QByteArray arr;
    arr.append(QString("%1").arg(sql.toLocal8Bit().size(),3,16,QChar('0'))+sql);
    if (type == EXC )
    {
        arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
        arr.insert(4,QString("0"));
        qDebug() << arr.size();
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
            qDebug() << "get message ";
        }
    }
    else
    {
        arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
        arr.insert(4,QString("1"));
        qDebug() << arr;
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
            qDebug() << "get result set ";
        }
    }
    if(getSet)
    {
        emit getResultSet(resultSet);
        resultSet.clear();
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
        //控制台输出获得的数据大小及内容
        qDebug() << "receive data size:";
        qDebug() << bufferSize;
        qDebug() << buffer;
        qDebug() << type;
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
    qDebug() << "read set?";
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    int i,j,num,column;
    QString key, value;
    QString str = tc->toUnicode(buffer.left(3));
    int row = str.toInt(0,16);
    buffer.remove(0,3);
    for (i =0;i<row;i++)
    {
        QVariantMap *object = new QVariantMap();
        str = tc->toUnicode(buffer.left(2));
        column = str.toInt(0,16);
        buffer.remove(0,2);
        for(j =0;j<column;j++)
        {
            key ="";
            value ="";
            str = tc->toUnicode(buffer.left(2));
            num = str.toInt(0,16);
            buffer.remove(0,2);
            key = tc->toUnicode(buffer.left(num));
            qDebug() << key;
            buffer.remove(0,num);
            str = tc->toUnicode(buffer.left(4));
            num = str.toInt(0,16);
            buffer.remove(0,4);
            value = tc->toUnicode(buffer.left(num));
            qDebug() << value;
            buffer.remove(0,num);
            object->insert(key,QVariant::fromValue(value));
        }
        resultSet.append(object);
    }
    buffer.clear();
    bufferSize =0;
    type = NONE;
    getSet = true;
}

void ChatClient::readMessage()
{
    bool flag = (bool)QString(buffer.at(0)).toInt();
    if (flag)
    {
        qDebug() << "sql statment execute successfully";
        getMsg = 1;
    }
    else
    {
        qDebug() << "failed in executing";
        getMsg =2;
    }
    buffer.clear();
    bufferSize =0;
    type = NONE;
}

bool ChatClient::connectToServer()
{
    client->connectToHost(QHostAddress(HOST),80);
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

