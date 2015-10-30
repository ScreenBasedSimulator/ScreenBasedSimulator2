#include "Connection.h"
#include "ConnectionClient.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include "crow_all.h"
#include "driver.h"

Connection::Connection(ConnectionClient* pConnectionClient)
    : m_pConnectionClient(pConnectionClient)
{
}

void Connection::handleMessage(std::string message) {
    m_pConnectionClient->HandleMessage("12");
}

void Connection::operator()()
{
    SetRunning(true);

    crow::SimpleApp app;
    Driver * client= (Driver *)m_pConnectionClient;
    CROW_ROUTE(app, "/")([this](){
        handleMessage("123");
        std::cout<<"HIHIHI"<<std::endl;
        crow::json::wvalue x;
        x["message"] = "Hello, World!";
        return x;
    });

    app.port(18080).multithreaded().run();

    // while (Running())
    // {
    //     std::string content;
    //     std::cin >> content;
    //     // std::cout<< "received the input: " << content<<std::endl;

        
    //     // 
    //     // std::cout<<"success!!!!!";
    //     // int bytes = read(socketfd, receive_buffer, sizeof receive_buffer);
    //     // if (bytes > 0)
    //     // {
    //     //     //fputs(receive_buffer, stdout);
    //     //     m_pConnectionClient->HandleMessage(std::string(receive_buffer));
    //     // }
    // }

    
}
