#ifndef FORMIPOD_H
#define FORMIPOD_H

#include <QWidget>

namespace Ui {
class FormIpod;
}

class FormIpod : public QWidget
{
    Q_OBJECT

public:
    explicit FormIpod(QWidget *parent = 0);
    ~FormIpod();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormIpod *ui;
    void * win;
};

#endif // FORMIPOD_H
