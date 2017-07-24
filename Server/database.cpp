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
    db.setPassword("");
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
        return 0;
    }
    else
    {
        qDebug() << "result:success";
        return 1;
    }
}
bool DataBase::DBExecuteWithoutOutput(QString sql)
{
    QSqlQuery query;
    bool flag = query.exec(sql);
    if(flag == false)
    {
        return 0;
    }
    else
    {
        return 1;
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
