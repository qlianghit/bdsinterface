#ifndef FORMWEATHER_H
#define FORMWEATHER_H

#include <QWidget>

namespace Ui {
class FormWeather;
}

class FormWeather : public QWidget
{
    Q_OBJECT

public:
    explicit FormWeather(QWidget *parent = 0);
    ~FormWeather();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);

private:
    Ui::FormWeather *ui;
    void * win;
};

#endif // FORMWEATHER_H
