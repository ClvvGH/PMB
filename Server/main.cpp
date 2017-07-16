#include "widget.h"
#include <QApplication>
#include <database.h>
#include <chatserver.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatServer *cs = new ChatServer();
    Widget w;
    w.show();
    DataBase *db = new DataBase();
    if(!db->DBConnect())
    {
        qDebug() << "open database failed";
    }
    return a.exec();
}
