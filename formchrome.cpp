#include "formchrome.h"
#include "ui_formchrome.h"
#include "mainwindow.h"
#include <QDebug>
#include <QWebView>


FormChrome::FormChrome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChrome)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.google.ca"));
}

FormChrome::~FormChrome()
{
    delete ui;
}


void FormChrome::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormChrome::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormChrome::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    this->hide();
    w->show();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
