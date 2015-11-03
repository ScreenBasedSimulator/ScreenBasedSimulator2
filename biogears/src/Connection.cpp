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

void Connection::operator()()
{
    SetRunning(true);

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([this](){
        return "BioGear Server by Screen Based Simulation Team";
    });

    CROW_ROUTE(app, "/patient/status")([this](){
        crow::json::wvalue x = GetPatientStatus();
        return x;
    });

    app.port(18080).multithreaded().run();
    
}
