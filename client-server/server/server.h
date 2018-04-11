#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    explicit Server(QString IP, qint16 port, QObject *parent=0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * server;
    QTcpSocket * socket;
    void AddToLog(QString text);
    int NumberWordInText(QString &text);
};

#endif // SERVER_H
