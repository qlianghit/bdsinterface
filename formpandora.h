#ifndef FORMPANDORA_H
#define FORMPANDORA_H

#include <QWidget>

namespace Ui {
class FormPandora;
}

class FormPandora : public QWidget
{
    Q_OBJECT

public:
    explicit FormPandora(QWidget *parent = 0);
    ~FormPandora();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormPandora *ui;
    void * win;
};

#endif // FORMPANDORA_H
