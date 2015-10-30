#ifndef CONNECTION_CLIENT_H
#define CONNECTION_CLIENT_H

#include <string>

class ConnectionClient
{
public:
    virtual ~ConnectionClient() {}
    virtual void HandleMessage(const std::string& message) = 0;
};

#endif
