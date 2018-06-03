#include "database.h"
DataBase::DataBase()
{

}

bool DataBase::DBConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hospital");
    db.setUserName("root");
    db.setPassword("1234");
    db.setPort(3306);
    if(!db.open())
    {
        return false;
    }
    return true;
}

bool DataBase::DBExecute(QString sql)
{
    QSqlQuery query;
    bool flag = query.exec(sql);
    qDebug() << "DataBase: executing:"+query.executedQuery();
    if(flag == false)
    {
        qDebug() << "result:failed";
        return false;
    }
    else
    {
        qDebug() << "result:success";
        return true;
    }
}
bool DataBase::DBExecuteWithoutOutput(QString sql)
{
    QSqlQuery query;
    bool flag = query.exec(sql);
    if(flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
QSqlQuery DataBase::DBQuery(QString sql)
{
    QSqlQuery query;
    bool flag = query.exec(sql);
    qDebug() << "DataBase: query: "+query.executedQuery();
    if(flag == false)
    {
        qDebug() << "result:failed";
    }
    else
    {
        qDebug() << "result:success";
    }
    return query;
}
