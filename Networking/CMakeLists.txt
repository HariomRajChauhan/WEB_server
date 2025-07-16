cmake_minimum_required(VERSION 3.10)
project(LiveHttpServer)

set(CMAKE_CXX_STANDARD 17)

# Source files
file(GLOB SOCKET_SRC "sockets/*.cpp")
file(GLOB SERVER_SRC "servers/*.cpp")

# Create executable
add_executable(server main.cpp ${SOCKET_SRC} ${SERVER_SRC})

# Include directories
target_include_directories(server PRIVATE sockets servers)

# Link libraries based on platform
if(WIN32)
    target_link_libraries(server ws2_32)
endif()


#### to build the project
    
# mkdir build
# cd build
# cmake ..
# cmake --build .
# ./server    # or ./server.exe on Windows