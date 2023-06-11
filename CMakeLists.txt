cmake_minimum_required(VERSION 3.24)
project(svgProjectNew)

set(CMAKE_CXX_STANDARD 17)

add_executable(svgProjectNew main.cpp Domain.cpp Domain.h Point.cpp Point.h Shape.cpp Shape.h)
