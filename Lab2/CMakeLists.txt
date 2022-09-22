cmake_minimum_required(VERSION 3.15)
project(Lab2Expressions)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2Expressions main.cpp ExpressionManagerInterface.h ExpressionManager.h ExpressionManager.cpp)