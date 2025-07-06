#ifndef connectingSocket_hpp
#define connectingSocket_hpp

#include <stdio.h>
#include "simpleSocket.hpp"

namespace HRS
{
    class connectingSocket : public simpleSocket
    {
        public:
            // constructor
            connectingSocket(int domain, int service, int protocol, int port, u_long interfac);

            // virtual function from parent
            int connect_to_network(int sock, struct sockaddr_in address);
    };

}

#endif // connectingSocket_hpp
