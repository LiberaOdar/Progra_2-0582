cmake_minimum_required(VERSION 4.2)
project(MemClientes)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemClientes main.cpp
        Bibllioteca/Funciones.cpp
        Bibllioteca/Funciones.h)
