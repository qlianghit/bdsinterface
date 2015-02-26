#ifndef FORMEXIT_H
#define FORMEXIT_H

#include <QWidget>

namespace Ui {
class FormExit;
}

class FormExit : public QWidget
{
    Q_OBJECT

public:
    explicit FormExit(QWidget *parent = 0);
    ~FormExit();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private slots:
    void on_pushButton_clicked();

private:
    Ui::FormExit *ui;
    void * win;
};

#endif // FORMEXIT_H
