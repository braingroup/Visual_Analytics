#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <QThread>
#include <QVector>

class QueryResult : public QThread
{
public:
    QueryResult();
    void setInstance(QString _nameTable, QString _nameField);
    void run();
    QVector <double> getInstance();
private:
    QVector <double> resultPoint;
    QString nameTable;
    QString nameField;
};



#endif // QUERYRESULT_H
