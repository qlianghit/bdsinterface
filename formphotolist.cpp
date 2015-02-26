#include "formphotolist.h"
#include "ui_formphotolist.h"
#include "mainwindow.h"
#include <QDebug>

#ifdef WIN32
#define ROOTPATH QString("C:/Documents and Settings/All Users/Documents/My Pictures/Sample Pictures")
#else
#define ROOTPATH QString("/disk/images")
#endif

FormPhotoList::FormPhotoList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPhotoList)
{
    ui->setupUi(this);

    //connect(this, SIGNAL(sendData(void*)), (QObject *)win, SLOT(receiveData(void*)));
    //connect((QObject *)win, SIGNAL(sendData(void*)), this, SLOT(receiveData(void*)));
    model = new MyQFileSystemModel(this);
    model->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    //model->setIconProvider();
    QStringList nameList;
    nameList << "*.jpg" << "*.png" << "*.gif";
    model->setNameFilters(nameList);
    model->setRootPath(ROOTPATH);

    ui->listView->setModel(model);
    ui->listView->setRootIndex(model->setRootPath(ROOTPATH));

    QFont listFont;
    listFont.setPointSize(10);
    listFont.setBold(true);
    listFont.setWeight(60);

    ui->listView->setFont(listFont);
    ui->listView->setIconSize(QSize(60,60));

    ui->labelAirplay->setPixmap(QPixmap(":/bds_UIs/airplay_s.png"));
    ui->labelBluetooth->setPixmap(QPixmap(":/bds_UIs/bluetooth_s.png"));
    ui->labelWifi->setPixmap(QPixmap(":/bds_UIs/wifi_s.png"));
    ui->labelPhoto->setPixmap(QPixmap(":/bds_UIs/image120.PNG"));
}

FormPhotoList::~FormPhotoList()
{
    delete ui;
}


void FormPhotoList::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormPhotoList::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}
/*
void FormPhotoList::on_pushButtonUp_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}*/

void FormPhotoList::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}

void FormPhotoList::on_listView_clicked(const QModelIndex &index)
{
    QString sPath = model->fileInfo(index).absoluteFilePath();
    qDebug() << "itme path:" <<sPath;
    ui->labelThumbnail->setPixmap(QPixmap(sPath));
    ui->labelThumbnail->setAlignment(Qt::AlignCenter);
}
