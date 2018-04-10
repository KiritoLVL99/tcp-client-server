#include "widget.h"
#include "ui_widget.h"
#include "client.h"
#include <QDebug>
#include <QMessageBox>
#include <QtGui>

bool fl=false;
Client *cli;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
}

void Widget::Init()
{
    //ui->idServ->setInputMask("000.000.000.000");
    //ui->QLEword->setValidator("a0c");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbSend_clicked()
{
    //ui->QLEword->setInputMask("a0");
    AddToLog(ui->QLEword->inputMask());
    char word[2048];

    QString temp=ui->QLEword->text();
    QByteArray ba=temp.toLatin1();
    strcpy(word,ba.data());

    cli->cli->write(word);
    AddToLog("send");
    QString fft = cli->cli->readAll();
    AddToLog("answer "+fft);
    //AddToLog(fft,Qt::black);

}

void Widget::on_pbConnect_clicked()
{
    QString adr = ui->idServ->text();
    quint16 port = ui->idPort->value();
    cli = new Client(adr,port);

    connect(cli->cli,SIGNAL(connected()),(this),SLOT(message()));
    //if(fl)
    //{
    //}
}

void Widget::on_pbDisconnect_clicked()
{
    cli->cli->disconnectFromHost();
    delete cli;

    AddToLog("Disconnect",Qt::red);

    ui->pbDisconnect->setEnabled(false);
    ui->pbConnect->setEnabled(true);
    ui->pbSend->setEnabled(false);
}

void Widget::message()
{
    AddToLog("Connect",Qt::green);
    ui->pbSend->setEnabled(true);
    ui->pbDisconnect->setEnabled(true);
    ui->pbConnect->setEnabled(false);


}

void Widget::AddToLog(QString text, QColor color)
{
    ui->listLog->insertItem(0, QTime::currentTime().toString()+" "+text);
    ui->listLog->item(0)->setTextColor(color);
}


