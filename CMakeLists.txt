cmake_minimum_required(VERSION 3.15)
project(asio_async_tcp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use vcpkg toolchain for dependencies (automatically handled from command line)
find_package(Threads REQUIRED)

# Client executable
add_executable(async_client async_client.cpp)
target_link_libraries(async_client PRIVATE Threads::Threads)

# Server executable
add_executable(async_server async_server.cpp)
target_link_libraries(async_server PRIVATE Threads::Threads)
