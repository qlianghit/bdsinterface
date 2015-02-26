#ifndef FORMSETTING_H
#define FORMSETTING_H

#include <QWidget>

namespace Ui {
class FormSetting;
}

class FormSetting : public QWidget
{
    Q_OBJECT

public:
    explicit FormSetting(QWidget *parent = 0);
    ~FormSetting();
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void receiveData(void *recvData);
    void on_pushButtonReturn_clicked();

signals:
    void sendData(void * sendData);


private:
    Ui::FormSetting *ui;
    void * win;
};

#endif // FORMSETTING_H
