#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include "connection.h"
#include "connectionoptions.h"
#include <QSqlQuery>

class MySqlConnection : public Connection
{
public:
    MySqlConnection(ConnectionOptions options);
    ~MySqlConnection();
    QVector<QString> makeQuery(QString query);
    QVector<QString> getTables();
    QVector<QString> getColumns(QString table);
    QVector<QString> getColumnData(QString table, QString column);
    QVector<recordCount> getColumnDataCounts(QString table, QString column);
};

#endif // MYSQLCONNECTION_H
