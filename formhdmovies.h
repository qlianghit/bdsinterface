#ifndef FORMHDMOVIES_H
#define FORMHDMOVIES_H

#include <QWidget>

namespace Ui {
class FormHDMovies;
}

class FormHDMovies : public QWidget
{
    Q_OBJECT

public:
    explicit FormHDMovies(QWidget *parent = 0);
    ~FormHDMovies();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormHDMovies *ui;
    void * win;
};

#endif // FORMHDMOVIES_H
