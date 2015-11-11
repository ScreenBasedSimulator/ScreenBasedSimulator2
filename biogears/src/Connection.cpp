#include "Connection.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

Connection::Connection(Driver* pDriver)
    : m_pDriver(pDriver)
{
}

void Connection::handleMessage(std::string message) {
    m_pDriver->HandleMessage("12");
}
crow::json::wvalue Connection::GetPatientStatus() {
    return m_pDriver->GetPatientStatus();
}
void Connection::BolusDrug(std::string drugName, double concentration, double dose){
    m_pDriver->BolusDrug(drugName, concentration, dose);
}

void Connection::AnesthesiaMachine(double oxygenFraction){
    m_pDriver->AnesthesiaMachine(oxygenFraction);
}

void Connection::operator()()
{
    SetRunning(true);

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([this](){
        return "BioGear Server by Screen Based Simulation Team";
    });

    CROW_ROUTE(app, "/patient/status")
    .methods("GET"_method)
    ([this](){
        crow::json::wvalue x = GetPatientStatus();
        return x;
    });

    CROW_ROUTE(app,"/patient/injection")
    .methods("POST"_method)
    ([this](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        std::string drugName = x["drug_name"].s();
        double concentration = x["concentration"].d();
        double dose = x["dose"].d();
        
        BolusDrug(drugName, concentration, dose);
        return crow::response{"successful"};
    });

    CROW_ROUTE(app,"/anesthesia_machine")
    .methods("POST"_method)
    ([this](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        double oxygenFraction = x["oxygen_fraction"].d();
        
        AnesthesiaMachine(oxygenFraction);
        return crow::response{"successful"};
    });

    app.port(23333).multithreaded().run();
    
}
