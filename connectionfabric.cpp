#include "connectionfabric.h"

ConnectionFabric::ConnectionFabric()
{

}

Connection* ConnectionFabric::getConnection(connections connection, ConnectionOptions options)
{
    if (connection == MYSQL)
    {
        return new MySqlConnection(options);
    }
    return NULL;
}
