#include <chatserver.h>

ChatServer::ChatServer(QObject *parent) :
    QObject(parent)
{
    bufferSize = 0;
    server = new QTcpServer();
    server->listen(QHostAddress::Any,4343);
    connect(server, SIGNAL(newConnection()),this , SLOT(acceptConnection()));
    connect(server,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(acceptError(QAbstractSocket::SocketError)));
}

void ChatServer::acceptConnection()
{
    socket = server->nextPendingConnection();
    recordClientAction("连接服务器");
    connect(socket, SIGNAL(readyRead()), this, SLOT(readFromClient()));
}
void ChatServer::readFromClient()
{
    buffer.append(socket->readAll());
    if(bufferSize==0)
    {
        QString strSize = QString(buffer.at(0))+QString(buffer.at(1))+QString(buffer.at(2))+QString(buffer.at(3));
        bufferSize =strSize.toInt(0,16);
        buffer.remove(0,5);
    }
    //判断数据是否读取完整
    if(bufferSize<=buffer.size())
    {
        readComplete();
    }
}
//从客户端读取数据完毕，开始分析数据
void ChatServer::readComplete()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(buffer);
    qDebug() << "receive data size";
    qDebug() << bufferSize;
    buffer.clear();
    bufferSize =0;
    CJson = doc.object();
    //解析
    requestType type = jsonDiscoding();
    if (type == EXC)
    {
        bool flag = DataBase::DBExecute(sql);
        if (flag)
        {
            //执行成功
            recordClientAction("执行sql语句");
            pushMessage(SUCCESS);
        }
        else
        {
            //执行失败
            pushMessage(FAILED);
        }
    }
    else
    {
        //查询
        QSqlQuery query = DataBase::DBQuery(sql);
        recordClientAction("查询数据");
        //将查询结果编辑成json对象，然后发送
        pushData(jsonCoding(query));
    }
    return;
}

ChatServer::requestType ChatServer::jsonDiscoding()
{
    QString type = CJson.take("type").toString();
    sql = CJson.take("sql").toString();
    if (!QString::compare(type,"query"))
    {
        return QUE;
    }
    else
    {
        return EXC;
    }
}

QJsonArray ChatServer::jsonCoding(QSqlQuery query)
{
    QSqlRecord record = query.record();
    QJsonObject json;
    QJsonArray SJson;
    while (query.next())
    {

        for(int i=0;i<record.count();i++)
        {
            json.insert(record.fieldName(i),QJsonValue::fromVariant(query.value(i)));
        }
        SJson.append(json);
    }
    return SJson;
}

void ChatServer::pushData(QJsonArray SJson)
{
    qDebug() << "record count before sending to peer";
    qDebug() << SJson.size();
    QJsonDocument *doc = new QJsonDocument(SJson);
    QByteArray arr =doc->toBinaryData();
    arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
    //返回类型
    arr.insert(4,"0");
    qDebug() << "BinaryData size:";
    qDebug() << arr.size();
    socket->write(arr);
    if (socket->waitForBytesWritten(30000))
    {
        qDebug() << "return result set successfully";
    }

}

void ChatServer::pushMessage(ExecResult result)
{
    QJsonObject json;
    if(result == SUCCESS)
    {
       json.insert("result","success");
    }
    else
    {
       json.insert("result","failed");
    }
    QJsonDocument *doc = new QJsonDocument(json);
    QByteArray arr = doc->toBinaryData();;
    arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
    arr.insert(4,"1");
    socket->write(arr);
    if (socket->waitForBytesWritten(30000))
    {
        qDebug() << "push message successfully";
    }
}

void ChatServer::recordClientAction(QString action)
{
    QDateTime datetime = QDateTime::currentDateTime();
    QString strDT = datetime.toString("yyyy-MM-dd hh:mm:ss");
    QString tmpSql = QString("INSERT INTO clientAction(ip, action, date) values('"+socket->peerAddress().toString()+"','"+action+"','"+strDT+"');");
    DataBase::DBExecuteWithoutOutput(tmpSql);
}
void ChatServer::acceptError(QAbstractSocket::SocketError error)
{
    qDebug() << error;
}
