#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "formsubmain.h"
#include "formphotolist.h"
#include "formairplay.h"
#include "formmusiclist.h"
#include "formmovielist.h"
#include "formexit.h"
#include "formhdmi.h"
#include "formipod.h"
#include "formsetting.h"
#include "formbluetooth.h"
#include "formairplay.h"
#include "formradio.h"
#include "formyoutube.h"
#include "formchrome.h"
#include "formdisc.h"


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButtonDown_clicked();

    void receiveData(void *recvData);

    void on_pushButtonImage_clicked();

    void on_pushButtonScreen_clicked();

    void on_pushButtonChrome_clicked();

    void on_pushButtonBlueThooth_clicked();

    void on_pushButtonDisk_clicked();

    void on_pushButtonMusic_clicked();

    void on_pushButtonMovie_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonSetting_clicked();

    void on_pushButtonIpod_clicked();

    void on_pushButtonHdmi3_clicked();

    void on_pushButtonHdmi2_clicked();

    void on_pushButtonHdmi1_clicked();

    void on_pushButtonRadio_clicked();

    void on_pushButtonYoutube_clicked();

signals:
    void sendData(void * sendData);

private:
    void display_subform(QWidget *form);
    Ui::MainWindow *ui;

    FormSubMain form;

    FormDisc formDisc;
    FormMusicList formMusicList;
    FormPhotoList formPhotoList;
    FormMovieList formMovieList;
    FormExit formExit;
    FormHDMI formHDMI;
    FormIpod formIpod;
    FormSetting formSetting;
    FormBlueTooth formBlueTooth;
    FormAirPlay formAirPlay;
    FormRadio formRadio;
    FormYoutube formYoutube;
    FormChrome formChrome;


};



#endif // MAINWINDOW_H
