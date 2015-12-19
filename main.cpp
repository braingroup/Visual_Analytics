#include "iostream"
#include <connectionfabric.h>

int main()
{
    ConnectionOptions options;
    options.hostname = "localhost";
    options.database = "grom";
    options.username = "root";
    options.password = "password";

    try
    {
        Connection* connection = ConnectionFabric::getConnection(MYSQL, options);
        QVector<recordCount> test  = connection->getColumnDataCounts("emails", "email");
        for (int i = 0; i < test.size(); i++)
        {
            std::cout << test[i].column.toUtf8().data() << " " << test[i].count << std::endl;
        }
        delete connection;
    }
    catch (ConnectionException)
    {
        std::cout << "Connection error" << std::endl;
    }

    return 0;
}
