cmake_minimum_required(VERSION 4.2)
project(MemLibros)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemLibros main.cpp
        Biblioteca/MetodoExactoMemoria.cpp
        Biblioteca/MetodoExactoMemoria.h
)
