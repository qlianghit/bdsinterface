#include "formhdmovies.h"
#include "ui_formhdmovies.h"
#include "mainwindow.h"
#include <QDebug>

FormHDMovies::FormHDMovies(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHDMovies)
{
    ui->setupUi(this);
}

FormHDMovies::~FormHDMovies()
{
    delete ui;
}


void FormHDMovies::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormHDMovies::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}


void FormHDMovies::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
