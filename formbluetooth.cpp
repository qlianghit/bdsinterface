#include "formbluetooth.h"
#include "ui_formbluetooth.h"
#include "mainwindow.h"
#include <QDebug>

FormBlueTooth::FormBlueTooth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBlueTooth)
{
    ui->setupUi(this);
}

FormBlueTooth::~FormBlueTooth()
{
    delete ui;
}


void FormBlueTooth::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormBlueTooth::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormBlueTooth::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}

