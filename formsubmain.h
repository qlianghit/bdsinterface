#ifndef FORMSUBMAIN_H
#define FORMSUBMAIN_H

#include <QWidget>
//#include "mainwindow.h"

namespace Ui {
class FormSubMain;
}

class FormSubMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormSubMain(QWidget *parent = 0);
    ~FormSubMain();

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButtonUp_clicked();

    void receiveData(void *recvData);

signals:
    void sendData(void * sendData);

private:
    Ui::FormSubMain *ui;
    void * win;
};

#endif // FORMSUBMAIN_H
