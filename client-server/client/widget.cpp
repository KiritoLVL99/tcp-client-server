#include "widget.h"
#include "ui_widget.h"
#include "client.h"
#include <QDebug>
#include <QMessageBox>
#include <QtGui>
#include <QFileDialog>
#include <QValidator>

Client *client;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->qleWord->setValidator(new QRegExpValidator( QRegExp( "[A-Za-z0-9]{1,50}" ) ));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbConnect_clicked()
{
    QString adr = ui->qleIDServ->text();
    quint16 port = ui->sbPort->value();
    client = new Client(adr,port);
    connect(client->socket,SIGNAL(connected()),(this),SLOT(message()));

}

void Widget::on_pbDisconnect_clicked()
{
    client->socket->disconnectFromHost();
    delete client;

    AddToLog("Disconnect",Qt::blue);
    Status('D');
}

void Widget::on_pbOpenFile_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
    ui->pathFile->clear();
    ui->pathFile->insert(str);
}

void Widget::on_pbSend_clicked()
{
    QFile file(ui->pathFile->text());
    if(!file.exists())
    {
        AddToLog("file not found",Qt::red);
        return;
    }

    file.open(QIODevice::ReadOnly);
    while(!file.atEnd())
    {
        QString str=file.readLine();
        QByteArray bb=str.toLatin1();
        client->socket->write(bb);
    }
    file.close();


    client->socket->write("!#*#!");

    char word[2048];
    QString temp=ui->qleWord->text();
    QByteArray ba=temp.toLatin1();
    strcpy(word,ba.data());

    client->socket->write(word);
    AddToLog("Send request");
    Status('S');
}

void Widget::on_pbAnsServ_clicked()
{
    QString ans = client->socket->readAll();
    ui->lineAns->clear();
    ui->lineAns->insert(ans);
    AddToLog("Get Answer: "+ans);

    Status('C');
}

void Widget::message()
{
    AddToLog("Connect",Qt::green);
    Status('C');
}

void Widget::AddToLog(QString text, QColor color)
{
    ui->listLog->insertItem(0, QTime::currentTime().toString()+" "+text);
    ui->listLog->item(0)->setTextColor(color);
}

void Widget::Status(const char st)
{
    switch (st) //D,C,S;
    {
    case 'D':
        ui->pbConnect->setEnabled(true);
        ui->pbDisconnect->setEnabled(false);
        ui->pbOpenFile->setEnabled(false);
        ui->pbSend->setEnabled(false);
        ui->pbAnsServ->setEnabled(false);
        ui->qleIDServ->setEnabled(true);
        ui->sbPort->setEnabled(true);
        break;
    case 'C':
        ui->pbConnect->setEnabled(false);
        ui->pbDisconnect->setEnabled(true);
        ui->pbOpenFile->setEnabled(true);
        ui->pbSend->setEnabled(true);
        ui->pbAnsServ->setEnabled(false);
        ui->qleIDServ->setEnabled(false);
        ui->sbPort->setEnabled(false);
        break;
    case 'S':
        ui->pbConnect->setEnabled(false);
        ui->pbDisconnect->setEnabled(true);
        ui->pbOpenFile->setEnabled(false);
        ui->pbSend->setEnabled(false);
        ui->pbAnsServ->setEnabled(true);
        ui->qleIDServ->setEnabled(false);
        ui->sbPort->setEnabled(false);
        break;
    default:
        break;
    }
}
