#include "formhdmi.h"
#include "ui_formhdmi.h"
#include "mainwindow.h"
#include <QDebug>


FormHDMI::FormHDMI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHDMI)
{
    ui->setupUi(this);
}

FormHDMI::~FormHDMI()
{
    delete ui;
}


void FormHDMI::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormHDMI::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormHDMI::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
