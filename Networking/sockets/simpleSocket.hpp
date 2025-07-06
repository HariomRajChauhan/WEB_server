#ifndef simpleSocket_hpp
#define simpleSocket_hpp

#include <stdio.h>
#include <iostream>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

namespace HRS
{
    class simpleSocket
    {

    private:
        struct sockaddr_in address;
        int sock;
        int connection;

    public:
        // constructor
        simpleSocket(int domain, int service, int protocol, int port, u_long interfac);

        // virtual functions to connect to the network
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

        // confirm that the socket or connection is properly established
        void test_connection(int);

        // geter functions
        struct sockaddr_in get_address();
        int get_socket();
        int get_connection();
        void set_connection(int conc);
    };
} // namespace hrs

#endif