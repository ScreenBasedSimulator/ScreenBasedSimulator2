#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof server_address);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(5000);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (struct sockaddr*)&server_address, sizeof server_address);

    listen(listenfd, 10);

    int connectionfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
    
    printf("Found client\n");

    char send_buffer[1024] = "Hello, world!\n\0";
    write(connectionfd, send_buffer, 1024);

    close(connectionfd);
}
