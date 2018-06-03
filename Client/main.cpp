#include <QApplication>
#include <network/chatclient.h>
#include <loginview.h>
#include <doctormainview.h>
#include <QTextCodec>
int identity = 0;
int ID = 0;
ChatClient *cc = new ChatClient();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginView loginView;
    while (!cc->connectToServer())
    {
        qDebug() << "failed in connecting to server";
    }
    loginView.show();
    return a.exec();
}
