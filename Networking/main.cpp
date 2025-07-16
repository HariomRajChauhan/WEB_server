#include <winsock2.h>
#include "servers/hrslibServer.hpp"

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }
    int PORT_NO;
    std::cout << "Enter Port No : ";
    std::cin >> PORT_NO;
    // serve the current directory
    HRS::liveServer server("./", PORT_NO);
    WSACleanup();

    return 0;
}