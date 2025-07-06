#ifndef bindingSocket_hpp
#define bindingSocket_hpp

#include <stdio.h>
#include "simpleSocket.hpp"

namespace HRS
{
    class bindingSocket : public simpleSocket
    {
    private:
        int binding;
    public:
        // constructor
        bindingSocket(int domain, int service, int protocol, int port, u_long interfac);

        // virtual function from parents
        int connect_to_network(int sock, struct sockaddr_in address);
    };

} // namespace HRS

#endif