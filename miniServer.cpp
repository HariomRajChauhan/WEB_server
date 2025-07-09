#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <direct.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define MAX_LEN 4096

std::string get_cwd()
{
    char buf[MAX_PATH];
    _getcwd(buf, MAX_PATH);
    return std::string(buf);
}

std::string url_decode(const std::string &s)
{
    std::string result;
    char ch;
    int i, ii;
    for (i = 0; i < s.length(); i++)
    {
        if (int(s[i]) == 37)
        {
            sscanf(s.substr(i + 1, 2).c_str(), "%x", &ii);
            ch = static_cast<char>(ii);
            result += ch;
            i = i + 2;
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}

void serve_file(SOCKET client, const std::string &path)
{
    std::ifstream file(path, std::ios::binary);
    if (file)
    {
        std::ostringstream ss;
        ss << file.rdbuf();
        std::string body = ss.str();
        std::string header = "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(body.size()) + "\r\n\r\n";
        send(client, header.c_str(), header.size(), 0);
        send(client, body.c_str(), body.size(), 0);
    }
    else
    {
        std::string notFound = "HTTP/1.1 404 Not Found\r\nContent-Length: 13\r\n\r\n404 Not Found";
        send(client, notFound.c_str(), notFound.size(), 0);
    }
}

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed.\n";
        closesocket(server);
        WSACleanup();
        return 1;
    }

    listen(server, 5);
    std::cout << "Serving directory: " << get_cwd() << "\n";
    std::cout << "Open http://localhost:8080/ in your browser.\n";

    char buffer[MAX_LEN];
    while (true)
    {
        SOCKET client = accept(server, nullptr, nullptr);
        if (client == INVALID_SOCKET)
            continue;
        memset(buffer, 0, MAX_LEN);
        int bytes = recv(client, buffer, MAX_LEN, 0);
        if (bytes > 0)
        {
            std::string request(buffer);
            size_t pos1 = request.find("GET ");
            size_t pos2 = request.find(" HTTP/");
            std::string path = "/";
            if (pos1 != std::string::npos && pos2 != std::string::npos)
            {
                path = request.substr(pos1 + 4, pos2 - (pos1 + 4));
                path = url_decode(path);
                if (path == "/")
                    path = "/index.html";
            }
            std::string fullPath = get_cwd() + path;
            serve_file(client, fullPath);
        }
        closesocket(client);
    }

    closesocket(server);
    WSACleanup();
    return 0;
}