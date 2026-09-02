cmake_minimum_required(VERSION 4.2)
project(SobreEstatica)

set(CMAKE_CXX_STANDARD 20)

add_library(SobreEstatica STATIC
        Sobrecarga.cpp)
