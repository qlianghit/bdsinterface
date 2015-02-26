#include "formairplay.h"
#include "ui_formairplay.h"
#include "mainwindow.h"
#include <QDebug>

FormAirPlay::FormAirPlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAirPlay)
{
    ui->setupUi(this);
}

FormAirPlay::~FormAirPlay()
{
    delete ui;
}


void FormAirPlay::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormAirPlay::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormAirPlay::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
