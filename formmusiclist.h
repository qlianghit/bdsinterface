#ifndef FORMMUSICLIST_H
#define FORMMUSICLIST_H

#include <QWidget>
#include <QFileSystemModel>
#include <QtMultimedia>

namespace Ui {
class FormMusicList;
}

class FormMusicList : public QWidget
{
    Q_OBJECT

public:
    explicit FormMusicList(QWidget *parent = 0);
    ~FormMusicList();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::FormMusicList *ui;
    void * win;
    QFileSystemModel *model;
};

#endif // FORMMUSICLIST_H
