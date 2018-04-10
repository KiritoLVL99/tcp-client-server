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
    QLineEdit *idServ;
    QSpinBox *idPort;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QListWidget *listLog;
    QLineEdit *QLEword;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(402, 368);
        pbSend = new QPushButton(Widget);
        pbSend->setObjectName(QStringLiteral("pbSend"));
        pbSend->setEnabled(false);
        pbSend->setGeometry(QRect(10, 190, 75, 23));
        pbSend->setCheckable(false);
        idServ = new QLineEdit(Widget);
        idServ->setObjectName(QStringLiteral("idServ"));
        idServ->setGeometry(QRect(40, 60, 91, 20));
        idServ->setMaxLength(15);
        idPort = new QSpinBox(Widget);
        idPort->setObjectName(QStringLiteral("idPort"));
        idPort->setGeometry(QRect(220, 70, 55, 20));
        idPort->setMinimum(1);
        idPort->setMaximum(60000);
        idPort->setValue(3425);
        pbConnect = new QPushButton(Widget);
        pbConnect->setObjectName(QStringLiteral("pbConnect"));
        pbConnect->setGeometry(QRect(10, 100, 75, 23));
        pbDisconnect = new QPushButton(Widget);
        pbDisconnect->setObjectName(QStringLiteral("pbDisconnect"));
        pbDisconnect->setEnabled(false);
        pbDisconnect->setGeometry(QRect(150, 110, 75, 23));
        listLog = new QListWidget(Widget);
        listLog->setObjectName(QStringLiteral("listLog"));
        listLog->setGeometry(QRect(10, 230, 381, 121));
        QLEword = new QLineEdit(Widget);
        QLEword->setObjectName(QStringLiteral("QLEword"));
        QLEword->setGeometry(QRect(10, 140, 113, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Client", nullptr));
        pbSend->setText(QApplication::translate("Widget", "Send", nullptr));
        idServ->setText(QApplication::translate("Widget", "127.0.2.17", nullptr));
        pbConnect->setText(QApplication::translate("Widget", "Connect", nullptr));
        pbDisconnect->setText(QApplication::translate("Widget", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
