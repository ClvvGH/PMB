#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QTextCodec>
class DataBase
{
public:
    DataBase();
    static bool DBConnect();
    static bool DBExecute(QString);
    static QSqlQuery DBQuery(QString);
};

#endif // DATABASE_H
