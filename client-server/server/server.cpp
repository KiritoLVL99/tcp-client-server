#include "server.h"
#include <QDebug>
#include <QCoreApplication>
#include <QtGui>
#include <QMap>

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if(!server->listen(QHostAddress("127.0.0.1"), 3425))
    {
        AddToLog("server is not started");
    }
    else
    {
        AddToLog("server is started");
        AddToLog("ip: 127.0.0.1 port: 3425");
    }
}

Server::Server(QString IP, qint16 port, QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if(!server->listen(QHostAddress(IP), port))
    {
        AddToLog("server is not started");
    }
    else
    {
        AddToLog("server is started");
        AddToLog("ip: "+IP+" port: "+QString::number(port));
    }
}

void Server::slotNewConnection()
{
    socket = server->nextPendingConnection();

    AddToLog("ClientConnect");

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotClientDisconnected);
}

void Server::slotServerRead()
{
    while(socket->bytesAvailable()>0)
    {
        QString array=socket->readAll();

        AddToLog("Received a new request from the client");

        QString ans = QString::number(NumberWordInText(array));

        AddToLog("The response to the client request: "+ans);

        QByteArray an=ans.toLatin1();
        socket->write(an);

    }
}

void Server::slotClientDisconnected()
{
    socket->close();
    AddToLog("ClientDisconnect");
}

void Server::AddToLog(QString text)
{
    qDebug()<<QTime::currentTime().toString()<<" "<<text;
}

int Server::NumberWordInText(QString &text)
{
    int f= text.indexOf("!#*#!");
    text[f]=' ';
    f+=4;
    text[f]=' ';
    f++;
    QString word="";
    for(int i=f;i<text.size();++i)
    {
        word+=text[i];
    }

    QMap<QString,int> tft;
    QString word1="";
    for(int i=0;i<text.size();++i)
    {
        if(text[i]!='\n'&& text[i]!='\r' && text[i]!=' ' && text[i]!='\0')
        {
            word1+=text[i];
        }
        else
        {
            tft[word1]++;
            word1="";
        }
    }
    return tft[word];
}
