cmake_minimum_required(VERSION 4.2)
project(AplicaBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicaBibEstatica main.cpp
        Biblioteca/Sobrecargas.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h)
