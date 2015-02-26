#include "formexit.h"
#include "ui_formexit.h"
#include "mainwindow.h"
#include <QDebug>


FormExit::FormExit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormExit)
{
    ui->setupUi(this);
}

FormExit::~FormExit()
{
    delete ui;
}


void FormExit::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormExit::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormExit::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}

void FormExit::on_pushButton_clicked()
{
    //quit();
}
