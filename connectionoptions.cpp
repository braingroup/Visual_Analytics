#include "connectionoptions.h"

ConnectionOptions::ConnectionOptions()
{

}

ConnectionOptions::~ConnectionOptions()
{

}

void ConnectionOptions::setDatabase(QString database)
{
    this->database = database;
}

void ConnectionOptions::setHostname(QString hostname)
{
    this->hostname = hostname;
}

void ConnectionOptions::setPassword(QString password)
{
    this->password = password;
}

void ConnectionOptions::setUsername(QString username)
{
    this->username = username;
}

