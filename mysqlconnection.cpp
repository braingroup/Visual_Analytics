#include "mysqlconnection.h"
#include "iostream"
#include <QMapIterator>
#include <QVariant>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>

using namespace std;

MySqlConnection::MySqlConnection(ConnectionOptions options)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(options.hostname);
    db.setUserName(options.username);
    db.setPassword(options.password);
    db.setDatabaseName(options.database);
    if (!db.open())
    {
        throw ConnectionException();
    }
}

MySqlConnection::~MySqlConnection()
{

}

QVector<QString> MySqlConnection::makeQuery(QString query)
{
    QVector<QString> result;
    QSqlQuery queryResult = db.exec(query);
    int colsNum = queryResult.record().count();
    while (queryResult.next())
    {
        QString record = "";
        for (int i = 0; i < colsNum; i++)
        {
            record += queryResult.value(i).toString() + (i == colsNum - 1 ? "" : " ");
        }
        result.append(record);
    }
    return result;
}

QVector<QString> MySqlConnection::getTables()
{
    return this->makeQuery("show tables;");
}

QVector<QString> MySqlConnection::getColumns(QString table)
{
    QVector<QString> result;
    QSqlQuery queryResult = db.exec("describe " + table);
    while (queryResult.next())
    {
        result.append(queryResult.value(0).toString());
    }
    return result;
}

QVector<QString> MySqlConnection::getColumnData(QString table, QString column)
{
    return this->makeQuery("select " + column + " from " + table);
}

QVector<recordCount> MySqlConnection::getColumnDataCounts(QString table, QString column)
{
    QVector<recordCount> result;
    QSqlQuery queryResult = db.exec("select " + column + ", count(*) from " + table + " group by " + column);
    while (queryResult.next())
    {
        recordCount rec;
        rec.column = queryResult.value(0).toString();
        rec.count = atoi(queryResult.value(1).toString().toUtf8().data());
        result.append(rec);
    }
    return result;
}

