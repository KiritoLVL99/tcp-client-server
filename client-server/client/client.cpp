#include "client.h"

Client :: Client()
{
    cli = new QTcpSocket();
    cli->connectToHost("localhost",3425);
}
Client :: Client(QString s, qint16 port)
{
    cli = new QTcpSocket();
    cli->connectToHost(s,port);
}
Client::~Client()
{
    delete cli;
}
