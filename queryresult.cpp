#include "queryresult.h"

#include <QDebug>
QueryResult::QueryResult()
{

}

void QueryResult::setInstance(QString _nameTable, QString _nameField)
{
    nameTable = _nameTable;
    nameField = _nameField;
}

void QueryResult::run()
{
    resultPoint.clear();
    if (0 == QString::compare(nameField, "строка 1")) {
        qDebug() << "query 1";
        for (int i=0; i<160; ++i)
        {
            resultPoint.push_back(-8 + (i/10.0));
        }
    }
    if (0 == QString::compare(nameField, "строка 2")) {
        qDebug() << "query 2";
        for (int i=0; i<160; ++i)
        {
            resultPoint.push_back(sin(-8 + (i/10.0)));
        }
    }
    if (0 == QString::compare(nameField, "строка 3")) {
        qDebug() << "query 3";
        for (int i=0; i<160; ++i)
        {
            resultPoint.push_back((-8 + (i/10.0))*(-8 + (i/10.0)));
        }
    }

    if (0 == QString::compare(nameField, "строка 4")) {
        qDebug() << "query 4";
        for (int i=0; i<160; ++i)
        {
            resultPoint.push_back(exp(-8 + (i/10.0)));
        }
    }


}

QVector<double> QueryResult::getInstance()
{
    return resultPoint;
}
