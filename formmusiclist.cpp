#include "formmusiclist.h"
#include "ui_formmusiclist.h"
#include "mainwindow.h"
#include <QDebug>

#ifdef WIN32
#define ROOTPATH QString("C:/Documents and Settings/All Users/Documents/My Music/Sample Music")
#else
#define ROOTPATH QString("/disk/musics")
#endif

FormMusicList::FormMusicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMusicList)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    //model->setIconProvider();
    QStringList nameList;
    nameList << "*.mp3" << "*.wav" << "*.wma";
    model->setNameFilters(nameList);
    model->setRootPath(ROOTPATH);

    ui->listView->setModel(model);
    ui->listView->setRootIndex(model->setRootPath(ROOTPATH));
    ui->labelAirplay->setPixmap(QPixmap(":/bds_UIs/airplay_s.png"));
    ui->labelBluetooth->setPixmap(QPixmap(":/bds_UIs/bluetooth_s.png"));
    ui->labelWifi->setPixmap(QPixmap(":/bds_UIs/wifi_s.png"));
    ui->labelMusic->setPixmap(QPixmap(":/bds_UIs/musicIcon_m.png"));

    QFont listFont;
    listFont.setPointSize(10);
    listFont.setBold(true);
    listFont.setWeight(60);

    ui->listView->setFont(listFont);
    ui->listView->setIconSize(QSize(60,60));

}

FormMusicList::~FormMusicList()
{
    delete ui;
}


void FormMusicList::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormMusicList::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormMusicList::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}

void FormMusicList::on_listView_clicked(const QModelIndex &index)
{

    QString fileName = index.model()->data(index,Qt::DisplayRole).toString();
    qDebug() << "fileName: " << fileName;

    if(fileName.endsWith(".mp3") || fileName.endsWith(".wma") || fileName.endsWith(".wav"))
    {
        ui->labelMusicName->setText(fileName);
        ui->labelThumbnail->setPixmap(QPixmap(":/bds_UIs/musicIcon.PNG"));

    }
    else
    {
        //ui->labelThumbnail->setPixmap(0);
    }

}
