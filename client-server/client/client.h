#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QMessageBox>

class Client /*: public QObject*/
{
    //Q_OBJECT
public:
    QTcpSocket* cli;
    //quint16     m_nNextBlockSize;

public:
    explicit Client(/*QObject *parent = 0*/);
    explicit Client(QString s, qint16 port/*, QObject *parent=0*/);
    ~Client();

public slots:
    //void message();
};

#endif // CLIENT_H
