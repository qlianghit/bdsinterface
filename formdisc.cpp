#include "formdisc.h"
#include "ui_formdisc.h"
#include "mainwindow.h"
#include <QDebug>


FormDisc::FormDisc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDisc)
{
    ui->setupUi(this);
}

FormDisc::~FormDisc()
{
    delete ui;
}


void FormDisc::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormDisc::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormDisc::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
