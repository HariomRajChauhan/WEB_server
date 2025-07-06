#include "listeningSocket.hpp"

// constructor
HRS::listeningSocket::listeningSocket(int domain, int service, int protocol, int port, u_long interfac, int bklg) : bindingSocket(domain, service, protocol, port, interfac)
{
    // set backlog variable
    backlog = bklg;
    // start listening to the network using listen() from winsocket lib
    start_listening();
    // confirm the connection was successful
    test_connection(listening);
}

// mutators
void HRS::listeningSocket::start_listening()
{
    listening = listen(get_socket(), backlog);
}


// getter

int HRS::listeningSocket::get_listening()
{
    return listening;
}

int HRS::listeningSocket::get_backlog()
{
    return backlog;
}