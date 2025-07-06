#ifndef simpleServer_hpp
#define simpleServer_hpp

#include <stdio.h>

#include "../hrslibNetworking.hpp"

namespace HRS
{
    class simpleServer
    {
        private:
            listeningSocket * socket;
        public:
            simpleServer(int domain, int service, int protocol, int port, u_long interfac, int bklg);
    };
}


#endif 