#include <chatserver.h>

ChatServer::ChatServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer();
    server->listen(QHostAddress::Any,6666);
    QObject::connect(server, SIGNAL(newConnection()),this , SLOT(acceptConnection()));
}

void ChatServer::acceptConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void ChatServer::readClient()
{
    QByteArray arr = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromBinaryData(arr);
    CJson = doc.object();
    //执行sql语句
    if (jsonDiscoding() == EXC)
    {
        if (DataBase::DBExecute(sql))
        {
            //执行成功
            qDebug() << "sql execute successfully";
            pushMessage(SUCCESS);
        }
        else
        {
            //执行失败
            qDebug() << "failed in sql executing";
            pushMessage(FAILED);
        }
    }
    else if (jsonDiscoding() == QUE)
    {
        //查询
        QSqlQuery query = DataBase::DBQuery(sql);
        //将查询结果编辑成json对象
        jsonCoding(query);
        pushData();
    }
    else
    {
        qDebug() << "客户端没有给定sql语句类型";
        return;
    }
    /*测试输出sql语句*/
    qDebug() << sql;
    /*结束*/
    return;
}

ChatServer::requestType ChatServer::jsonDiscoding()
{
    QString type = CJson.take("type").toString();
    sql = CJson.take("sql").toString();
    if (!QString::compare(type,"que"))
    {
        return QUE;
    }
    else
    {
        return EXC;
    }
}

void ChatServer::jsonCoding(QSqlQuery query)
{
    QSqlRecord record = query.record();
    QJsonObject json;
    while (query.next())
    {
        for(int i=0;i<record.count();i++)
        {
            json.insert(record.fieldName(i),QJsonValue::fromVariant(query.value(i)));
        }
        SJson.append(json);
    }
}

void ChatServer::pushData()
{
    QJsonDocument *doc = new QJsonDocument(SJson);
    QByteArray arr = doc->toBinaryData();
    socket->write(arr);
    socket->waitForBytesWritten(3000);
}

void ChatServer::pushMessage(ExecResult result)
{
    QJsonObject json;
    json.insert("returnType","message");
    if(result == SUCCESS)
    {
       json.insert("result","success");
    }
    else
    {
       json.insert("result","failed");
    }
    QJsonDocument *doc = new QJsonDocument(json);
    QByteArray arr = doc->toBinaryData();
    socket->write(arr);
}
