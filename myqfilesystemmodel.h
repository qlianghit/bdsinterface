#ifndef MYQFILESYSTEMMODEL_H
#define MYQFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QObject>

class MyQFileSystemModel : public QFileSystemModel
{
public:
    MyQFileSystemModel(QObject * parent = 0);
    ~MyQFileSystemModel();
    QVariant data( const QModelIndex& index, int role )const;

};


#endif // MYQFILESYSTEMMODEL_H

