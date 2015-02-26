#ifndef FORMCHROME_H
#define FORMCHROME_H

#include <QWidget>

namespace Ui {
class FormChrome;
}

class FormChrome : public QWidget
{
    Q_OBJECT

public:
    explicit FormChrome(QWidget *parent = 0);
    ~FormChrome();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormChrome *ui;
    void * win;
};

#endif // FORMCHROME_H
