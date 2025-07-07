#include "simpleServer.hpp"

HRS::simpleServer::simpleServer(int domain, int service, int protocol, int port, u_long interfac, int bklg)
{
    socket = new listeningSocket(domain, service, protocol, port, interfac, bklg);
    // delete socket;
}

HRS::listeningSocket* HRS::simpleServer::get_socket(){
    return socket;
}