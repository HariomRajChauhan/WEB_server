#include "connectingSocket.hpp"

// constructor

HRS::connectingSocket::connectingSocket(int domain, int service, int protocol, int port, u_long interfac) : simpleSocket(domain, service, protocol, port, interfac)
{
    set_connection(connect_to_network(get_socket(), get_address()));
    test_connection(get_connection());
}

// definition of the conect to network virtual function

int HRS::connectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    return connect( sock, (struct sockaddr *)&address, sizeof(address));
}