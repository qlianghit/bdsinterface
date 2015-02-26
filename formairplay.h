#ifndef FORMAIRPLAY_H
#define FORMAIRPLAY_H

#include <QWidget>

namespace Ui {
class FormAirPlay;
}

class FormAirPlay : public QWidget
{
    Q_OBJECT

public:
    explicit FormAirPlay(QWidget *parent = 0);
    ~FormAirPlay();

    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormAirPlay *ui;
    void * win;
};

#endif // FORMAIRPLAY_H
