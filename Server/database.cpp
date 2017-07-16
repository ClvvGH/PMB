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
    qDebug() << query.executedQuery();
    if(flag == false)
    {
        qDebug() << "failed";
        return 0;
    }
    else
    {
        qDebug() << "success";
        return 1;
    }
}

QSqlQuery DataBase::DBQuery(QString sql)
{
    QSqlQuery query;
    bool flag = query.exec(sql);
    qDebug() << query.executedQuery();
    if(flag == false)
    {
        qDebug() << "failed";
    }
    else
    {
        qDebug() << "success";
    }
    return query;
}
