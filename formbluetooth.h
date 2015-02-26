#ifndef FORMBLUETOOTH_H
#define FORMBLUETOOTH_H

#include <QWidget>

namespace Ui {
class FormBlueTooth;
}

class FormBlueTooth : public QWidget
{
    Q_OBJECT

public:
    explicit FormBlueTooth(QWidget *parent = 0);
    ~FormBlueTooth();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormBlueTooth *ui;
    void * win;
};

#endif // FORMBLUETOOTH_H
