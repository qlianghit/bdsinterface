#include "formmovielist.h"
#include "ui_formmovielist.h"
#include "mainwindow.h"
#include <QDebug>

#ifdef WIN32
#define ROOTPATH QString("C:/Documents and Settings/All Users/Documents/My Videos")
#else
#define ROOTPATH QString("/disk/movies")
#endif


FormMovieList::FormMovieList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMovieList)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    //model->setIconProvider();
    QStringList nameList;
    nameList << "*.ts" << "*.mpg" << "*.mp4";
    model->setNameFilters(nameList);
    model->setRootPath(ROOTPATH);

    ui->listView->setModel(model);
    ui->listView->setRootIndex(model->setRootPath(ROOTPATH));
    ui->labelAirplay->setPixmap(QPixmap(":/bds_UIs/airplay_s.png"));
    ui->labelBluetooth->setPixmap(QPixmap(":/bds_UIs/bluetooth_s.png"));
    ui->labelWifi->setPixmap(QPixmap(":/bds_UIs/wifi_s.png"));
    ui->labelMovie->setPixmap(QPixmap(":/bds_UIs/MovieIcon128.PNG"));

    QFont listFont;
    listFont.setPointSize(10);
    listFont.setBold(true);
    listFont.setWeight(60);

    ui->listView->setFont(listFont);
    ui->listView->setIconSize(QSize(60,60));

}

FormMovieList::~FormMovieList()
{
    delete ui;
}


void FormMovieList::receiveData(void *recvData)
{
    qDebug() << "FormSubMain::receiveData" << recvData;
    win = recvData;
}

bool FormMovieList::eventFilter(QObject *obj, QEvent *event)
{
    //default

    if (event->type() == QEvent::Enter)
    {

    }else
    {
        return QWidget::eventFilter(obj, event);
    }


}

void FormMovieList::on_pushButtonReturn_clicked()
{
    MainWindow * w = (MainWindow *)win;
    w->show();
    this->hide();
    emit sendData(this);
    qDebug() << "FormSubMain emit send data." << this;
}

void FormMovieList::on_listView_clicked(const QModelIndex &index)
{
    QString fileName = index.model()->data(index,Qt::DisplayRole).toString();
    qDebug() << "movie fileName: " << fileName;

    if(fileName.endsWith(".ts") || fileName.endsWith(".mpg") || fileName.endsWith(".wav"))
    {
        ui->labelMovieName->setText(fileName);
        ui->labelThumbnail->setPixmap(QPixmap(":/bds_UIs/movie512.png"));

    }
    else
    {
        //ui->labelThumbnail->setPixmap(0);
    }
}
