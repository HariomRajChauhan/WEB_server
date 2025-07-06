#ifndef listeningSocket_hpp
#define listeningSocket_hpp

#include <stdio.h>
#include "bindingSocket.hpp"

namespace HRS
{

    class listeningSocket : public bindingSocket
    {
    private:
        int backlog;
        int listening;

    public:
        listeningSocket(int domain, int service, int protocol, int port, u_long interfac, int bklg);

        void start_listening();
        int get_listening();
        int get_backlog();
    };
}

#endif // listeningSocket_hpp