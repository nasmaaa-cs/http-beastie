cmake_minimum_required(VERSION 3.10)
project(http_beastie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

add_executable(server src/main.cpp src/utils.cpp)

target_link_libraries(server PRIVATE Boost::system Threads::Threads)

target_include_directories(server PRIVATE include)
