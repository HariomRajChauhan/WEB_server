#include "testServer.hpp"

HRS::testServer::testServer() : simpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    lunch();
}


void HRS::testServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_socket(), (struct sockaddr *) &address, &addrlen);
    read(new_socket, buffer, MAX_LEN);
}

void HRS::testServer::handaler()
{
    std::cout << buffer << std::endl;
}

void HRS::testServer::responder()
{
    char * hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void HRS::testServer::lunch()
{
    while(true)
    {
         std::cout << "==== Waiting ====="<< std::endl;
         acceptor();
         handaler();
         responder();
         std::cout << "==== Done ====="<< std::endl;
    }
}
