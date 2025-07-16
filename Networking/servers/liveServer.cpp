#include "liveServer.hpp"
#include <fstream>
#include <sstream>
#include <cstring>
#include <filesystem>

#ifdef _WIN32
#include <winsock2.h>
#define CLOSESOCKET closesocket
#else
#include <unistd.h>
#define CLOSESOCKET close
#endif

namespace fs = std::filesystem;

// Add to liveServer.cpp or a new helper file
#include <filesystem>
namespace fs = std::filesystem;

std::string generate_directory_listing(const std::string &dir)
{
    std::ostringstream html;
    html << "<!DOCTYPE html><html><head><meta http-equiv='refresh' content='2'><title>Directory Listing</title></head><body>";
    html << "<h2>Directory listing for " << dir << "</h2><ul>";
    for (const auto &entry : fs::directory_iterator(dir))
    {
        std::string name = entry.path().filename().string();
        html << "<li><a href='" << name << "'>" << name << "</a></li>";
    }
    html << "</ul></body></html>";
    return html.str();
}

HRS::liveServer::liveServer(const std::string &root, int PORT_NO) : simpleServer(AF_INET, SOCK_STREAM, 0, PORT_NO, INADDR_ANY, 10), rootDir(root)
{
    lunch();
}

void HRS::liveServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);
    memset(buffer, 0, MAX_LEN);
    new_socket = accept(get_socket()->get_socket(), (struct sockaddr *)&address, &addrlen);
    int bytesRead = recv(new_socket, buffer, MAX_LEN, 0);
    if (bytesRead == SOCKET_ERROR)
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    else
        std::cout << "Bytes Read : " << bytesRead << std::endl;
}

void HRS::liveServer::handaler()
{
    std::cout << buffer << std::endl;
}

// responder
void HRS::liveServer::responder()
{
    std::string request(buffer);
    size_t pos1 = request.find("GET ");
    size_t pos2 = request.find("HTTP/");
    std::string path = "/";

    if (pos1 != std::string::npos && pos2 != std::string::npos)
    {
        path = request.substr(pos1 + 4, pos2 - (pos1 + 4));
        if (path == "/")
            path = "/index.html";  // default fallback
    }

    std::string fullPath = rootDir + path;

    // Try to serve file
    std::ifstream file(fullPath, std::ios::binary);
    if (file)
    {
        std::ostringstream ss;
        ss << file.rdbuf();
        std::string body = ss.str();

        // === AUTO-REFRESH FOR index.html ===
        if (path == "/index.html")
        {
            size_t headPos = body.find("<head>");
            if (headPos != std::string::npos)
            {
                headPos += 6; // insert after <head>
                body.insert(headPos, "<meta http-equiv='refresh' content='2'>");
            }
            else
            {
                // fallback inject at top
                body = "<meta http-equiv='refresh' content='2'>" + body;
            }
        }

        std::string header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + std::to_string(body.size()) + "\r\n\r\n";
        send(new_socket, header.c_str(), header.size(), 0);
        send(new_socket, body.c_str(), body.size(), 0);
    }
    else if (fs::is_directory(rootDir + path) || (path == "/index.html" && !fs::exists(fullPath)))
    {
        // Serve directory listing with auto-refresh
        std::string dirPath = rootDir + (path == "/index.html" ? "/" : path);
        std::string body = generate_directory_listing(dirPath);
        std::string header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + std::to_string(body.size()) + "\r\n\r\n";
        send(new_socket, header.c_str(), header.size(), 0);
        send(new_socket, body.c_str(), body.size(), 0);
    }
    else
    {
        std::string notFound = "HTTP/1.1 404 Not Found\r\nContent-Length: 13\r\n\r\n404 Not Found";
        send(new_socket, notFound.c_str(), notFound.size(), 0);
    }

    CLOSESOCKET(new_socket);
}


void HRS::liveServer::lunch()
{
    while (true)
    {
        std::cout << "==== Waiting ====" << std::endl;
        acceptor();
        handaler();
        responder();
        std::cout << "==== Done ====" << std::endl;
    }
}