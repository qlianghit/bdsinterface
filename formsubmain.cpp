#include "formsubmain.h"
#include "ui_formsubmain.h"
#include <QDebug>
#include "mainwindow.h"

FormSubMain::FormSubMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSubMain)
{
    ui->setupUi(this);
    qDebug() << "FormSubMain::FormSubMain";
/*
    connect(this, SIGNAL(sendData(void*)), (QObject *)win, SLOT(receiveData(void*)));
    connect((QObject *)win, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    ui->pushButtonPandora->installEventFilter(this);
    ui->pushButtonChrome->installEventFilter(this);

    ui->pushButtonWeather->installEventFilter(this);
    ui->pushButtonWifi->installEventFilter(this);
    ui->pushButtonHDMovie->installEventFilter(this);
*/
}

FormSubMain::~FormSubMain()
{
    delete ui;
}

void FormSubMain::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormSubMain::eventFilter(QObject *obj, QEvent *event)
{
    QString itemName = "Pandora";
    QString itemDescription = "Play Your Loved Music with Pandora";

    if (event->type() == QEvent::Enter)
    {
        if (obj == (QObject*)ui->pushButtonPandora) {

            itemName = "Pandora";
            itemDescription = "Play Your Loved Music with Pandora";

        }else if (obj == (QObject*)ui->pushButtonChrome) {
            itemName = "Music";
            itemDescription = "Google Chrome";
        }else if (obj == (QObject*)ui->pushButtonWeather) {
            itemName = "Weather";
            itemDescription = "Local and International Weather Broadcast";

        }else if (obj == (QObject*)ui->pushButtonHDMovie) {
            itemName = "Movie";
            itemDescription = "Play HD Moives";

        }else if (obj == (QObject*)ui->pushButtonWifi) {
            itemName = "Exit";
            itemDescription = "WiFi Setting";

        }


        ui->labelItemName->setText(itemName);
        ui->labelItemDescription->setText(itemDescription);
        return true;
    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormSubMain::on_pushButtonUp_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}
