#include "formradio.h"
#include "ui_formradio.h"
#include "mainwindow.h"
#include <QDebug>


FormRadio::FormRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRadio)
{
    ui->setupUi(this);
}

FormRadio::~FormRadio()
{
    delete ui;
}


void FormRadio::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormRadio::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormRadio::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
