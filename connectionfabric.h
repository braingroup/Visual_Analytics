#include <connection.h>
#include <mysqlconnection.h>

#ifndef CONNECTIONFABRIC_H
#define CONNECTIONFABRIC_H

enum connections
{
    MYSQL,
    POSTGRESQL,
    ORACLE
};

class ConnectionFabric
{
public:
    ConnectionFabric();
    static Connection* getConnection(connections connection, ConnectionOptions options);
};

#endif // CONNECTIONFABRIC_H
