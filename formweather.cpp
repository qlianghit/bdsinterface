#include "formweather.h"
#include "ui_formweather.h"
#include "mainwindow.h"
#include <QDebug>

FormWeather::FormWeather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormWeather)
{
    ui->setupUi(this);
}

FormWeather::~FormWeather()
{
    delete ui;
}


void FormWeather::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormWeather::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormWeather::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
