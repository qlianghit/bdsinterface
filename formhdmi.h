#ifndef FORMHDMI_H
#define FORMHDMI_H

#include <QWidget>

namespace Ui {
class FormHDMI;
}

class FormHDMI : public QWidget
{
    Q_OBJECT

public:
    explicit FormHDMI(QWidget *parent = 0);
    ~FormHDMI();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormHDMI *ui;
    void * win;
};

#endif // FORMHDMI_H
