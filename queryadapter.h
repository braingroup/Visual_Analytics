#ifndef QUERYADAPTER_H
#define QUERYADAPTER_H

#include "drawableobject.h"
#include "queryresult.h"

class QueryAdapter : public DrawableObject
{
  public:
    QueryAdapter( QueryResult* p, QString _nameTable, QString _nameGraph, QVector <QString> _fields);
    ~QueryAdapter();
    QVector<double> getValues(QString _nameField, QString _nameTable);
  private:
    QueryResult* query;
};

#endif // QUERYADAPTER_H
