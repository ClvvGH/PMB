#include <network/chatserver.h>

ChatServer::ChatServer(int socketDescriptor,QObject *parent) :
    QObject(parent)
{
    buffer.clear();
    bufferSize =0;
    sql = "";
    type = NONE;
    this->client = new QTcpSocket();
    client->setSocketDescriptor(socketDescriptor);
    connect(client, SIGNAL(readyRead()), this, SLOT(readFromClient()));
}

void ChatServer::readFromClient()
{
    buffer.append(client->readAll());
    if(bufferSize==0)
    {
        qDebug() << buffer;
        QString strSize = QString(buffer.at(0))+QString(buffer.at(1))+QString(buffer.at(2))+QString(buffer.at(3));
        bufferSize =strSize.toInt(0,16);
        type = (requestType)QString(buffer.at(4)).toInt(0,10);
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
    //控制台输出获得的数据大小及内容
    qDebug() << "receive data size:";
    qDebug() << bufferSize;
    qDebug() << buffer;
    //判断类型
    if (type == EXC)
    {
        getSql();
        if (DataBase::DBExecute(sql))
        {
            //执行成功
            recordClientAction("执行sql语句");
            sql = "";
            pushMessage(SUCCESS);
        }
        else
        {
            //执行失败
            sql = "";
            pushMessage(FAILED);
        }
    }
    else if (type == QUE)
    {
        getSql();
        QSqlQuery query = DataBase::DBQuery(sql);
        pushData(query);
        recordClientAction("查询数据");
    }
    else if (type == ALARM)
    {
        recordClientAction("报警");
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        QString strSize = tc->toUnicode(buffer.left(2));
        buffer.remove(0,2);
        int size = strSize.toInt(0,16);
        QString strID = tc->toUnicode(buffer.left(size));
        buffer.remove(0,size);
        int position = QString(buffer.at(0)).toInt();
        buffer.remove(0,1);
        emit alarm(strID.toInt(),client->peerAddress().toString(),position);
        buffer.clear();
        bufferSize =0;
        type =NONE;
    }
    else
    {
        //类型未定义，忽略该请求
        qDebug() << "receive a request with a unknown type ";
    }
}

//从缓冲区里获取sql语句
void ChatServer::getSql()
{
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    QString strSize = tc->toUnicode(buffer.left(3));
    buffer.remove(0,3);
    int size =strSize.toInt(0,16);
    sql = tc->toUnicode(buffer.left(size));
    //清理接受缓存区
    buffer.clear();
    bufferSize =0;
    type = NONE;
}

void ChatServer::pushData(QSqlQuery query)
{
    QByteArray arr ="";
    QSqlRecord record = query.record();
    QString str;
    //记录数
    arr.append(QString("%1").arg(query.size(),3,16,QChar('0')));
    while (query.next())
    {
        //列数
        arr.append(QString("%1").arg(record.count(),2,16,QChar('0')));
        for(int i=0;i<record.count();i++)
        {
            str = query.value(i).toString();
            //key长度
            arr.append(QString("%1").arg(record.fieldName(i).size(),2,16,QChar('0'))+record.fieldName(i));
            //value长度
            arr.append(QString("%1").arg(str.toLocal8Bit().size(),4,16,QChar('0'))+str);
        }
    }
    arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
    arr.insert(4,"0");
    client->write(arr);
    if (client->waitForBytesWritten(3000))
    {
        qDebug() << "send result set back successfully";
    }
    //控制台输出要发送给客户端的数据大小及内容,以及二进制数据大小
    qDebug() << "record count before sending to peer:";
    qDebug() << query.size();
    qDebug() << "Binary size to send:";
    qDebug() << arr.size();
    qDebug() << arr;
}

void ChatServer::pushMessage(ExecResult result)
{
    QByteArray arr="";
    if(result == SUCCESS)
    {
        arr.append("1");
    }
    else
    {
        arr.append("0");
    }
    arr.insert(0,QString("%1").arg(arr.size(),4,16,QChar('0')));
    arr.insert(4,"1");
    qDebug() << arr;
    client->write(arr);
    if (client->waitForBytesWritten(3000))
    {
        qDebug() << "push message successfully";
    }
}

void ChatServer::recordClientAction(QString action)
{
    QDateTime datetime = QDateTime::currentDateTime();
    QString strDT = datetime.toString("yyyy-MM-dd hh:mm:ss");
    QString tmpSql = QString("INSERT INTO clientAction(ip, action, date) values('"+client->peerAddress().toString()+"','"+action+"','"+strDT+"');");
    DataBase::DBExecuteWithoutOutput(tmpSql);
}

ChatServer::~ChatServer()
{
    client->disconnect();
}
