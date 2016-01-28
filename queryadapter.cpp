#include "queryadapter.h"

#include "queryresult.h"

QueryAdapter::QueryAdapter( QueryResult* p, QString _nameTable, QString _nameGraph, QVector <QString> _fields)
{
    query = p;
    nameTable = _nameTable;
    fields = _fields;
    nameGraph = _nameGraph;
}

QueryAdapter::~QueryAdapter()
{
    if (query != NULL) delete query;
}

QVector<double> QueryAdapter::getValues(QString _nameField, QString _nameTable)
{
    query->setInstance(_nameTable, _nameField);
    query->run();
    return query->getInstance();
}
