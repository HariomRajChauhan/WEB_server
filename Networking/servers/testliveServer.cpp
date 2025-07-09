#include <winsock2.h>
#include "liveServer.hpp"

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }
    // serve the current directory
    HRS::liveServer server("./");
    WSACleanup();

    return 0;
}