cmake_minimum_required(VERSION 4.2)
project(MemIncClientes)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemIncClientes main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h)
