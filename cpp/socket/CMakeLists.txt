cmake_minimum_required(VERSION 3.20)

project(SocketLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads REQUIRED)

add_executable(udpServer src/udpServer.cpp)
add_executable(udpClient src/udpClient.cpp)

add_executable(tcpServer src/tcpServer.cpp)
add_executable(tcpClient src/tcpClient.cpp)

add_executable(chatServer src/chatServer.cpp)
add_executable(chatClient src/chatClient.cpp)

target_link_libraries(chatServer PRIVATE Threads::Threads)
target_link_libraries(chatClient PRIVATE Threads::Threads)
