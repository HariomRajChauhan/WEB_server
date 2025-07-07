#include "listeningSocket.hpp"

int main()
{
    bool start_server;
    char start_key;
    std::cout << "Press S to Start the server" <<std::endl;
    std::cin >> start_key ;
    if(start_key == 's' || start_key == 'S')
        start_server = true;
        else
            start_server = false;
        
    while (start_server)
    {
    #ifdef _WIN32
        WSADATA wsaData;
        int wsaerr = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (wsaerr != 0)
        {
            std::cerr << "WSAStartup failed: " << wsaerr << std::endl;
            return 1;
        }
    #endif
        std::cout << "Starting..." << std::endl;

        // std::cout << "Binding Socket..." << std::endl;
        // HRS::bindingSocket bs = HRS::bindingSocket(AF_INET, SOCK_STREAM, 0, 8081, INADDR_ANY);

        // to check the port is using or not in terminal-code
        // netstat -ano | find "8082"
        std::cout << "Listening Socket..." << std::endl;
        HRS::listeningSocket ls = HRS::listeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);

        std::cout << "Success!" << std::endl;

    #ifdef _WIN32
        WSACleanup();
    #endif
    }
    return 0;
}