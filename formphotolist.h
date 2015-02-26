#ifndef FORMPHOTOLIST_H
#define FORMPHOTOLIST_H

#include <QWidget>
#include <QFileSystemModel>
#include "myqfilesystemmodel.h"

namespace Ui {
class FormPhotoList;
}

class FormPhotoList : public QWidget
{
    Q_OBJECT

public:
    explicit FormPhotoList(QWidget *parent = 0);
    ~FormPhotoList();

    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);

signals:
    void sendData(void * sendData);


private slots:

    void on_pushButtonReturn_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::FormPhotoList *ui;
    void * win;
    MyQFileSystemModel *model;
};

#endif // FORMPHOTOLIST_H
