#ifndef liveServer_hpp
#define liveServer_hpp

#include <string>

#include "simpleServer.hpp"

namespace HRS
{
    class liveServer : public simpleServer
    {
        private:
            char buffer[MAX_LEN] = {0};
            int new_socket;
            std::string rootDir;
            void acceptor() override;
            void handaler() override;
            void responder() override;

        public:
            liveServer(const std::string& root = "Networking/servers/", int PORT_NO = 8000);
            void lunch() override;
    };
}

#endif