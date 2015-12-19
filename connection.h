#ifndef CONNECTION_H
#define CONNECTION_H
#include "QString"
#include "QObject"
#include "QSqlDatabase"
#include <exception>
#include <QVector>

struct ConnectionOptions{
    QString hostname;
    QString username;
    QString password;
    QString database;
};

struct recordCount{
    QString column;
    unsigned long count;
};


class Connection : public QObject
{
    Q_OBJECT
protected:
    QSqlDatabase db;

public:
    virtual QVector<QString> makeQuery(QString query) = 0;
    virtual QVector<QString> getTables() = 0;
    virtual QVector<QString> getColumns(QString table) = 0;
    virtual QVector<QString> getColumnData(QString table, QString column) = 0;
    virtual QVector<recordCount> getColumnDataCounts(QString table, QString column) = 0;
};

class ConnectionException : public std::exception
{
    virtual const char* what() const throw()
      {
        return "Connection exception";
      }
};

#endif // CONNECTION_H
