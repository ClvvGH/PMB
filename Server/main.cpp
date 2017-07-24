#include <QApplication>
#include <database.h>
#include <chatserver.h>
#include <mainview.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatServer *cs = new ChatServer();
    DataBase *db = new DataBase();
    if(!db->DBConnect())
    {
        qDebug() << "open database failed";
    }
    MainView w;
    w.show();
    return a.exec();

}
