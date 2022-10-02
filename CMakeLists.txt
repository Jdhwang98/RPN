cmake_minimum_required(VERSION 3.23)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList main.cpp LinkedList.cpp LinkedList.h Stack.cpp Stack.h Node.h RPN.cpp RPN.h Queue.cpp Queue.h)
