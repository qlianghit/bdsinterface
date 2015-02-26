#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "formsubmain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "==";

    return a.exec();
    qDebug() << "end";

}
