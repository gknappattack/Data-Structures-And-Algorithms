cmake_minimum_required(VERSION 3.15)
project(TodoList)

set(CMAKE_CXX_STANDARD 14)

add_executable(TodoList main.cpp TodoList.h TodoListInterface.h)