#include <QCoreApplication>
#include "server.h"
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout), cin(stdin);

    QString ip,pt;

    qDebug()<<"enter ip server:";
    cin>>ip;

    qDebug()<<"enter port server:";
    cin>>pt;

    qint16 port=pt.toInt();
    Server server(ip,port);

    return a.exec();
}
