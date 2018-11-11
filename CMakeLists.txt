cmake_minimum_required(VERSION 3.10)
project(String)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wformat")

add_executable(String main.cpp String.cpp)