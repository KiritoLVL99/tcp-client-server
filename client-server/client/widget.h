#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pbSend_clicked();  
    void on_pbConnect_clicked();
    void on_pbDisconnect_clicked();
    void message();

private:
    Ui::Widget *ui;
    void AddToLog(QString text, QColor color = Qt::black);
    void Init();
};

#endif // WIDGET_H
