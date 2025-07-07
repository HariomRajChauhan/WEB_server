#include "testServer.hpp"

HRS::testServer::testServer() : simpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    lunch();
}

void HRS::testServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);
    memset(buffer, 0, MAX_LEN); // Clear buffer
    new_socket = accept(get_socket()->get_socket(), (struct sockaddr *)&address, &addrlen);
    int bytesRead = recv(new_socket, buffer, MAX_LEN, 0);
    if (bytesRead == SOCKET_ERROR) {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    } else {
        std::cout << "Bytes read: " << bytesRead << std::endl;
    }
}

void HRS::testServer::handaler()
{
    std::cout << buffer << std::endl;
}

void HRS::testServer::responder()
{
    const char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void HRS::testServer::lunch()
{
    while (true)
    {
        std::cout << "==== Waiting =====" << std::endl;
        acceptor();
        handaler();
        responder();
        std::cout << "==== Done =====" << std::endl;
    }
}
