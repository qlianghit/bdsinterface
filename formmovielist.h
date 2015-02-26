#ifndef FORMMOVIELIST_H
#define FORMMOVIELIST_H

#include <QWidget>
#include <QFileSystemModel>

namespace Ui {
class FormMovieList;
}

class FormMovieList : public QWidget
{
    Q_OBJECT

public:
    explicit FormMovieList(QWidget *parent = 0);
    ~FormMovieList();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::FormMovieList *ui;
    void * win;
    QFileSystemModel *model;
};

#endif // FORMMOVIELIST_H
