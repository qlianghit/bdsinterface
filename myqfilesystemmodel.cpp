#include "myqfilesystemmodel.h"
#include <QDebug>

MyQFileSystemModel::MyQFileSystemModel(QObject *parent)
    :QFileSystemModel(parent)
{
}


MyQFileSystemModel::~MyQFileSystemModel()
{

}

QVariant MyQFileSystemModel::data( const QModelIndex& index, int role )const
{

    if( role == Qt::DecorationRole )
    {
        qDebug() << "DecorationRole";
        return QVariant(QIcon(QPixmap(":/bds_UIs/image60.PNG")));
    }

    return QFileSystemModel::data(index, role);
}
