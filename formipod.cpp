#include "formipod.h"
#include "ui_formipod.h"
#include "mainwindow.h"
#include <QDebug>


FormIpod::FormIpod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormIpod)
{
    ui->setupUi(this);
}

FormIpod::~FormIpod()
{
    delete ui;
}


void FormIpod::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormIpod::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormIpod::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
