cmake_minimum_required(VERSION 3.17)
project(CS170_Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(header)

add_executable(CS170_Project_1
        header/Node.h
        header/problem.h
        header/Tree.h
        mainTree.cpp)
