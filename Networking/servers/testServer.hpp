#ifndef testServer_hpp
#define testServer_hpp

#include <stdio.h>

#include "simpleServer.hpp"

namespace HRS
{
    class testServer : public simpleServer
    {
    private:
        char buffer[MAX_LEN] = {0};
        int new_socket;
        void acceptor();
        void handaler();
        void responder();

    public:
        testServer();
        void lunch();
    };
}

#endif