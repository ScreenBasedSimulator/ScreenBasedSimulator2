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
Connection::Connection(ConnectionClient* pConnectionClient)
    : m_pConnectionClient(pConnectionClient)
{
}

void Connection::operator()()
{
    SetRunning(true);

    while (Running())
    {
        std::string content;
        std::cin >> content;
        // std::cout<< "received the input: " << content<<std::endl;

        m_pConnectionClient->HandleMessage(content);
        // 
        // std::cout<<"success!!!!!";
        // int bytes = read(socketfd, receive_buffer, sizeof receive_buffer);
        // if (bytes > 0)
        // {
        //     //fputs(receive_buffer, stdout);
        //     m_pConnectionClient->HandleMessage(std::string(receive_buffer));
        // }
    }

    
}
