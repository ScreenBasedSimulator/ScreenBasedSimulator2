#ifndef DRIVER_H
#define DRIVER_H

#include "Engine.h"
#include "Connection.h"

class Connection;
class Engine;

class Driver
{
public:
    Driver();

    void Initialize();

    void Run();
    void HandleMessage(const std::string& message);
    crow::json::wvalue GetPatientStatus();
    void BolusDrug(std::string drugName, double concentration, double dose);
    void AnesthesiaMachine(double oxygenFraction);

private:
    Engine* m_engine;
    Connection* m_connection;
};

#endif
