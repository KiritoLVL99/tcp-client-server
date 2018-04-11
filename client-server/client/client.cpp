#include "client.h"

Client :: Client()
{
    socket = new QTcpSocket();
    socket->connectToHost("localhost",3425);
}
Client :: Client(QString IP, qint16 port)
{
    socket = new QTcpSocket();
    socket->connectToHost(IP,port);
}
Client::~Client()
{
    delete socket;
}
