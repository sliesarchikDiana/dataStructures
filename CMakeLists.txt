cmake_minimum_required(VERSION 3.30)
project(dataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(dataStructures main.cpp
        SinglyLinkedList.cpp
        DoublyLinkedList.h
        DoublyLinkedList.cpp
        Queue.cpp
        Queue.h)
