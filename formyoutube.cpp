#include "formyoutube.h"
#include "ui_formyoutube.h"
#include "mainwindow.h"
#include <QDebug>
#include <QWebView>


FormYoutube::FormYoutube(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormYoutube)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.youtube.ca"));
}

FormYoutube::~FormYoutube()
{
    delete ui;
}


void FormYoutube::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormYoutube::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormYoutube::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
