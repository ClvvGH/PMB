#include <QApplication>
#include <network/chatclient.h>
#include <loginview.h>
#include <doctormainview.h>
#include <QTextCodec>
#include <QFont>
#include <QFontDatabase>
int identity = 0;
int ID = 0;
ChatClient *cc = new ChatClient();

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    //测试风格
    QFile file(":/styleSheet/pithy.qss");
    file.open(QFile::ReadOnly);
    QString ss = QString(file.readAll());
    qApp->setStyleSheet(ss);
    LoginView loginView;
    while (!cc->connectToServer())
    {
    }

    loginView.show();
    return a.exec();
}
