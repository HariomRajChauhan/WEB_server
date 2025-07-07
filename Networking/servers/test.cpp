#include "testServer.hpp"
#include <winsock2.h>

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }
    HRS::testServer t;

    WSACleanup();
    return 0;
}