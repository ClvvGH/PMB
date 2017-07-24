#ifndef JSONMODEL_H
#define JSONMODEL_H
#include <QStandardItemModel>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
class JsonModel : public QStandardItemModel
{
public:
    JsonModel(QJsonArray);
};

#endif // JSONMODEL_H
