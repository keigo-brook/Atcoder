cmake_minimum_required(VERSION 3.3)
project(ABC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    006/b.cpp
    ABC.iml)

add_executable(ABC ${SOURCE_FILES})