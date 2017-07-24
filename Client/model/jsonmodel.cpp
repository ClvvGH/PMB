#include "jsonmodel.h"

JsonModel::JsonModel(QJsonArray arr)
{
    QStringList keysList = arr.at(0).toObject().keys();
    int row = arr.size();
    int column = keysList.size();
    int i,j;
    setRowCount(row);
    setColumnCount(column);
    for (i=0;i<column;i++)
    {
        QStandardItem *item = new QStandardItem();
        item->setData(keysList.at(i),Qt::DisplayRole);
        qDebug() << keysList.at(i);
        setHorizontalHeaderItem(i,item);
    }
    for (i=0;i<row;i++)
        for(j=0;j<column;j++)
        {
            QStandardItem *item = new QStandardItem();
            item->setData(arr.at(i).toObject().take(keysList.at(j)),Qt::DisplayRole);
            qDebug() << arr.at(i).toObject().take(keysList.at(j));
            setItem(i,j,item);
        }
    qDebug() << keysList.at(1);
}

