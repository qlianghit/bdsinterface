#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QDialog>
#include <QApplication>

#include "formsubmain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //form = new FormSubMain(this);
    //form->hide();

    connect(this, SIGNAL(sendData(void*)), &form, SLOT(receiveData(void*)));
    connect(&form, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));


    connect(this, SIGNAL(sendData(void*)), &formDisc, SLOT(receiveData(void*)));
    connect(&formDisc, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formMusicList, SLOT(receiveData(void*)));
    connect(&formMusicList, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formPhotoList, SLOT(receiveData(void*)));
    connect(&formPhotoList, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formMovieList, SLOT(receiveData(void*)));
    connect(&formMovieList, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formExit, SLOT(receiveData(void*)));
    connect(&formExit, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formHDMI, SLOT(receiveData(void*)));
    connect(&formHDMI, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formIpod, SLOT(receiveData(void*)));
    connect(&formIpod, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formSetting, SLOT(receiveData(void*)));
    connect(&formBlueTooth, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formAirPlay, SLOT(receiveData(void*)));
    connect(&formAirPlay, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formBlueTooth, SLOT(receiveData(void*)));
    connect(&formBlueTooth, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formRadio, SLOT(receiveData(void*)));
    connect(&formRadio, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formYoutube, SLOT(receiveData(void*)));
    connect(&formYoutube, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));

    connect(this, SIGNAL(sendData(void*)), &formChrome, SLOT(receiveData(void*)));
    connect(&formChrome, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));


    ui->pushButtonDisk->installEventFilter(this);
    ui->pushButtonMusic->installEventFilter(this);

    ui->pushButtonImage->installEventFilter(this);
    ui->pushButtonMovie->installEventFilter(this);
    ui->pushButtonExit->installEventFilter(this);
    ui->pushButtonHdmi1->installEventFilter(this);
    ui->pushButtonHdmi2->installEventFilter(this);
    ui->pushButtonHdmi3->installEventFilter(this);
    ui->pushButtonIpod->installEventFilter(this);
    ui->pushButtonSetting->installEventFilter(this);
    ui->pushButtonBlueThooth->installEventFilter(this);
    ui->pushButtonScreen->installEventFilter(this);
    ui->pushButtonRadio->installEventFilter(this);
    ui->pushButtonYoutube->installEventFilter(this);
    ui->pushButtonChrome->installEventFilter(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(void *recvData)
{
    qDebug() << "MainWindow receiveData." << recvData;

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // This function repeatedly call for those QObjects
    // which have installed eventFilter (Step 2)
    QString itemName = "";
    QString itemDescription = "";

    if (event->type() == QEvent::Enter)
    {
        if (obj == (QObject*)ui->pushButtonDisk) {

            itemName = "Disc";
            itemDescription = "Play Optical Discs";

        }else if (obj == (QObject*)ui->pushButtonMusic) {
            itemName = "Music";
            itemDescription = "Play Music";
        }else if (obj == (QObject*)ui->pushButtonImage) {
            itemName = "Image";
            itemDescription = "Browse Image";

        }else if (obj == (QObject*)ui->pushButtonMovie) {
            itemName = "Movie";
            itemDescription = "Play Movie";

        }else if (obj == (QObject*)ui->pushButtonExit) {
            itemName = "Exit";
            itemDescription = "EXIT App";

        }else if (obj == (QObject*)ui->pushButtonHdmi1) {
            itemName = "HDMI1";
            itemDescription = "Play HDMI1";

        }else if (obj == (QObject*)ui->pushButtonHdmi2) {
            itemName = "HDMI2";
            itemDescription = "Play HDMI2";

        }else if (obj == (QObject*)ui->pushButtonHdmi3) {
            itemName = "HDMI3";
            itemDescription = "Play HDMI3";

        }else if (obj == (QObject*)ui->pushButtonIpod) {
            itemName = "iPod";
            itemDescription = "Play Music from iPod";

        }else if (obj == (QObject*)ui->pushButtonSetting) {
            itemName = "Setting";
            itemDescription = "Setting options";

        }else if (obj == (QObject*)ui->pushButtonBlueThooth) {
            itemName = "BlueThooth";
            itemDescription = "Play Music Through BlueThooth";

        }else if (obj == (QObject*)ui->pushButtonScreen) {
            itemName = "AirPlay";
            itemDescription = "Play Music";

        }else if (obj == (QObject*)ui->pushButtonRadio) {
            itemName = "Radio";
            itemDescription = "Play Radio";

        }else if (obj == (QObject*)ui->pushButtonYoutube) {
            itemName = "Youtube";
            itemDescription = "Video Share Youtube";
        }else if (obj == (QObject*)ui->pushButtonChrome) {
            itemName = "Chrome";
            itemDescription = "Google Chrome";
        }








        ui->labelItemName->setText(itemName);
        ui->labelItemDescription->setText(itemDescription);
        return true;
    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}


void MainWindow::display_subform(QWidget *form)
{

    form->show();
    this->hide();
    emit sendData(this);
    qDebug() << "emit data " << form->objectName();

}

void MainWindow::on_pushButtonDown_clicked()
{
    display_subform(&form);
}

void MainWindow::on_pushButtonImage_clicked()
{
    display_subform(&formPhotoList);
}

void MainWindow::on_pushButtonScreen_clicked()
{
    display_subform(&formAirPlay);

}

void MainWindow::on_pushButtonChrome_clicked()
{
    display_subform(&formChrome);
}

void MainWindow::on_pushButtonBlueThooth_clicked()
{
    display_subform(&formBlueTooth);
}

void MainWindow::on_pushButtonDisk_clicked()
{
    display_subform(&formDisc);
}

void MainWindow::on_pushButtonMusic_clicked()
{
    display_subform(&formMusicList);
}

void MainWindow::on_pushButtonMovie_clicked()
{
    display_subform(&formMovieList);
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
    //display_subform(&formExit);
}

void MainWindow::on_pushButtonSetting_clicked()
{
    display_subform(&formSetting);
}

void MainWindow::on_pushButtonIpod_clicked()
{
    display_subform(&formIpod);
}

void MainWindow::on_pushButtonHdmi3_clicked()
{
    display_subform(&formHDMI);
}

void MainWindow::on_pushButtonHdmi2_clicked()
{
    display_subform(&formHDMI);
}

void MainWindow::on_pushButtonHdmi1_clicked()
{
    display_subform(&formHDMI);
}

void MainWindow::on_pushButtonRadio_clicked()
{
    display_subform(&formRadio);
}

void MainWindow::on_pushButtonYoutube_clicked()
{
    display_subform(&formYoutube);
}
