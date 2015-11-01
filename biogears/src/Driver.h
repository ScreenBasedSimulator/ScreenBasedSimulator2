#ifndef DRIVER_H
#define DRIVER_H

#include "Engine.h"
#include "ConnectionClient.h"
#include "Connection.h"

class Driver : public ConnectionClient
{
public:
    Driver();

    void Initialize();

    void Run();
    virtual void HandleMessage(const std::string& message) override;
//    crow::json::wvalue GetPatientStatus();

private:
    Engine m_engine;
    Connection m_connection;
};

#endif
