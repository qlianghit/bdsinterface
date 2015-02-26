#ifndef FORMDLNA_H
#define FORMDLNA_H

#include <QWidget>

namespace Ui {
class FormDLNA;
}

class FormDLNA : public QWidget
{
    Q_OBJECT

public:
    explicit FormDLNA(QWidget *parent = 0);
    ~FormDLNA();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormDLNA *ui;
    void * win;
};

#endif // FORMDLNA_H
