#include "formsetting.h"
#include "ui_formsetting.h"
#include "mainwindow.h"
#include <QDebug>


FormSetting::FormSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSetting)
{
    ui->setupUi(this);
}

FormSetting::~FormSetting()
{
    delete ui;
}

void FormSetting::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormSetting::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormSetting::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
