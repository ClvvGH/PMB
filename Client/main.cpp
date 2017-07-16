#include "widget.h"
#include <QApplication>
#include <chatclient.h>

ChatClient *cc = new ChatClient();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!cc->connectToServer())
    {
        qDebug() << "failed in connecting to server";
    }
    Widget w;
    w.show();

    return a.exec();
}
