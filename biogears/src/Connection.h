#ifndef CONNECTION_H
#define CONNECTION_H

#include "Runnable.h"

class ConnectionClient;

class Connection : public Runnable
{
public:
    Connection(ConnectionClient* pConnectionClient);

    virtual void operator()() override;

private:
    ConnectionClient* m_pConnectionClient = nullptr;
    void handleMessage(std::string a);
};

#endif
