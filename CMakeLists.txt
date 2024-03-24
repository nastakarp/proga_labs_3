cmake_minimum_required(VERSION 3.27)
project(proga_lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(proga_lab3 main.cpp
        MarkerString.cpp
        MarkerText.cpp
        Node.h
        Node.cpp)
