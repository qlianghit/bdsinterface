#include "formdlna.h"
#include "ui_formdlna.h"
#include "mainwindow.h"
#include <QDebug>


FormDLNA::FormDLNA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDLNA)
{
    ui->setupUi(this);
}

FormDLNA::~FormDLNA()
{
    delete ui;
}


void FormDLNA::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormDLNA::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormDLNA::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
