#include <QApplication>
#include <database/database.h>
#include <network/chatserver.h>
#include <network/servercontroller.h>
#include <mainview.h>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    DataBase *db = new DataBase();
    if(!db->DBConnect())
    {
        qDebug() << "open database failed";
    }
    MainView w;
    w.show();
    return a.exec();
}
