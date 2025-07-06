#include "simpleSocket.hpp"

// default constructor

HRS::simpleSocket::simpleSocket(int domain, int service, int protocol, int port, u_long interfac)
{
    // define address
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interfac);

    // established socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

// virtual functions to connect to the network

void HRS::simpleSocket::test_connection(int item_to_test)
{
    // confirm that the socket or connection is properly established
    if (item_to_test < 0)
    {
#ifdef _WIN32
        int err = WSAGetLastError();
        std::cerr << "Failed to connect...: " << err << std::endl;

#else
        perror("Failed to connect..");

#endif
        exit(EXIT_FAILURE);
    }
}

// geter functions
struct sockaddr_in HRS::simpleSocket::get_address()
{
    return address;
}
int HRS::simpleSocket::get_socket()
{
    return sock;
}
int HRS::simpleSocket::get_connection()
{
    return connection;
}

// setter functions

void HRS::simpleSocket::set_connection(int conc)
{
    connection = conc;
}
