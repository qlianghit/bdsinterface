#include "formpandora.h"
#include "ui_formpandora.h"
#include "mainwindow.h"
#include <QDebug>

FormPandora::FormPandora(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPandora)
{
    ui->setupUi(this);
}

FormPandora::~FormPandora()
{
    delete ui;
}


void FormPandora::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormPandora::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormPandora::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
