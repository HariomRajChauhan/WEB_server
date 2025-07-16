#ifndef simpleServer_hpp
#define simpleServer_hpp

#define MAX_LEN 3000

#include <stdio.h>

#include "../sockets/hrslibSocket.hpp"
#include <unistd.h>

namespace HRS
{
    class simpleServer
    {
    private:
        listeningSocket *socket;
        virtual void acceptor() = 0;
        virtual void handaler() = 0;
        virtual void responder() = 0;

    public:
        simpleServer(int domain, int service, int protocol, int port, u_long interfac, int bklg);
        virtual void lunch() = 0;
        listeningSocket *get_socket();
    };
}

#endif