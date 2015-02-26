#ifndef FORMYOUTUBE_H
#define FORMYOUTUBE_H

#include <QWidget>

namespace Ui {
class FormYoutube;
}

class FormYoutube : public QWidget
{
    Q_OBJECT

public:
    explicit FormYoutube(QWidget *parent = 0);
    ~FormYoutube();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);

private:
    Ui::FormYoutube *ui;
    void * win;
};

#endif // FORMYOUTUBE_H
