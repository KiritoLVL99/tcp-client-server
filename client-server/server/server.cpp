#include "server.h"
#include <QDebug>
#include <QCoreApplication>

Server::Server(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress("127.0.0.1"), 3425))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
        qDebug()<<"ip: 127.0.0.1 port: 3425";
    }
}

Server::Server(QString s, qint16 port, QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress(s), port))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
        qDebug()<<"ip: "<<s<<" port: "<<port;
    }
}

void Server::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
    qDebug()<<"this is the client";

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &Server::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &Server::slotClientDisconnected);
}

void Server::slotServerRead()
{
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();

        mTcpSocket->write(array);
    }
}

void Server::slotClientDisconnected()
{
    mTcpSocket->close();
    qDebug()<<"good bye client";
}
