#include "bindingSocket.hpp"

// default constructor for the set the connection and test it
HRS::bindingSocket::bindingSocket(int domain, int service, int protocol, int port, u_long interfac) : simpleSocket(domain, service, protocol, port, interfac)
{
    set_connection(connect_to_network(get_socket(), get_address()));
    test_connection(get_connection());
}

// implimenting the connect_to_network virtual function
int HRS::bindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}

