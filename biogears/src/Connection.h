#ifndef CONNECTION_H
#define CONNECTION_H

#include "Runnable.h"
#include "Driver.h"

class Driver;

class Connection : public Runnable
{
public:
    Connection(Driver* pDriver);

    virtual void operator()() override;

private:
    Driver* m_pDriver = nullptr;
    void handleMessage(std::string a);
    crow::json::wvalue GetPatientStatus();
};

#endif
