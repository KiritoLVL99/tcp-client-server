#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QMessageBox>

class Client
{
    //Q_OBJECT
public:
    QTcpSocket* socket;

public:
    explicit Client();
    explicit Client(QString IP, qint16 port);
    ~Client();
};

#endif // CLIENT_H
