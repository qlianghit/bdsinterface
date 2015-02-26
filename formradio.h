#ifndef FORMRADIO_H
#define FORMRADIO_H

#include <QWidget>

namespace Ui {
class FormRadio;
}

class FormRadio : public QWidget
{
    Q_OBJECT

public:
    explicit FormRadio(QWidget *parent = 0);
    ~FormRadio();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormRadio *ui;
    void * win;
};

#endif // FORMRADIO_H
