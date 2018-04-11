/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pbSend;
    QLineEdit *qleIDServ;
    QSpinBox *sbPort;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QListWidget *listLog;
    QLineEdit *qleWord;
    QPushButton *pbOpenFile;
    QLineEdit *pathFile;
    QLineEdit *lineAns;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pbAnsServ;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(484, 422);
        pbSend = new QPushButton(Widget);
        pbSend->setObjectName(QStringLiteral("pbSend"));
        pbSend->setEnabled(false);
        pbSend->setGeometry(QRect(240, 60, 75, 23));
        pbSend->setCheckable(false);
        qleIDServ = new QLineEdit(Widget);
        qleIDServ->setObjectName(QStringLiteral("qleIDServ"));
        qleIDServ->setGeometry(QRect(10, 30, 101, 20));
        qleIDServ->setMaxLength(15);
        sbPort = new QSpinBox(Widget);
        sbPort->setObjectName(QStringLiteral("sbPort"));
        sbPort->setGeometry(QRect(130, 30, 55, 20));
        sbPort->setMinimum(1);
        sbPort->setMaximum(60000);
        sbPort->setValue(3425);
        pbConnect = new QPushButton(Widget);
        pbConnect->setObjectName(QStringLiteral("pbConnect"));
        pbConnect->setGeometry(QRect(10, 60, 75, 23));
        pbDisconnect = new QPushButton(Widget);
        pbDisconnect->setObjectName(QStringLiteral("pbDisconnect"));
        pbDisconnect->setEnabled(false);
        pbDisconnect->setGeometry(QRect(110, 60, 75, 23));
        listLog = new QListWidget(Widget);
        listLog->setObjectName(QStringLiteral("listLog"));
        listLog->setGeometry(QRect(10, 160, 461, 251));
        qleWord = new QLineEdit(Widget);
        qleWord->setObjectName(QStringLiteral("qleWord"));
        qleWord->setGeometry(QRect(220, 30, 113, 20));
        qleWord->setMaxLength(2048);
        pbOpenFile = new QPushButton(Widget);
        pbOpenFile->setObjectName(QStringLiteral("pbOpenFile"));
        pbOpenFile->setEnabled(false);
        pbOpenFile->setGeometry(QRect(370, 60, 75, 23));
        pathFile = new QLineEdit(Widget);
        pathFile->setObjectName(QStringLiteral("pathFile"));
        pathFile->setGeometry(QRect(350, 30, 113, 20));
        pathFile->setReadOnly(true);
        lineAns = new QLineEdit(Widget);
        lineAns->setObjectName(QStringLiteral("lineAns"));
        lineAns->setEnabled(true);
        lineAns->setGeometry(QRect(350, 110, 113, 20));
        lineAns->setReadOnly(true);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(20, 10, 81, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(130, 10, 61, 16));
        pbAnsServ = new QPushButton(Widget);
        pbAnsServ->setObjectName(QStringLiteral("pbAnsServ"));
        pbAnsServ->setEnabled(false);
        pbAnsServ->setGeometry(QRect(240, 110, 75, 23));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(250, 10, 51, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(360, 10, 101, 20));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 90, 131, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Client", nullptr));
        pbSend->setText(QApplication::translate("Widget", "Send", nullptr));
        qleIDServ->setInputMask(QApplication::translate("Widget", "000.000.000.000", nullptr));
        qleIDServ->setText(QApplication::translate("Widget", "127.0.0.1", nullptr));
        pbConnect->setText(QApplication::translate("Widget", "Connect", nullptr));
        pbDisconnect->setText(QApplication::translate("Widget", "Disconnect", nullptr));
        qleWord->setText(QApplication::translate("Widget", "youword", nullptr));
        pbOpenFile->setText(QApplication::translate("Widget", "OpenFile", nullptr));
        label->setText(QApplication::translate("Widget", "Server IP addres", nullptr));
        label_2->setText(QApplication::translate("Widget", "Server Port", nullptr));
        pbAnsServ->setText(QApplication::translate("Widget", "GetAnswer", nullptr));
        label_3->setText(QApplication::translate("Widget", "Your word", nullptr));
        label_4->setText(QApplication::translate("Widget", "Path to your file .txt", nullptr));
        label_5->setText(QApplication::translate("Widget", "Response to your request", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
