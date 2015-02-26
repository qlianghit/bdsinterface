#ifndef FORMDISC_H
#define FORMDISC_H

#include <QWidget>

namespace Ui {
class FormDisc;
}

class FormDisc : public QWidget
{
    Q_OBJECT

public:
    explicit FormDisc(QWidget *parent = 0);
    ~FormDisc();
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);

private:
    Ui::FormDisc *ui;
    void * win;

};

#endif // FORMDISC_H
