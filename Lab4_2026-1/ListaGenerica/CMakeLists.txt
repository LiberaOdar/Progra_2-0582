cmake_minimum_required(VERSION 4.2)
project(ListaGenerica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaGenerica main.cpp
        Biblioteca/BibliotecaGenerica.cpp
        Biblioteca/BibliotecaGenerica.h
        Biblioteca/BibliotecaEnteros.cpp
        Biblioteca/BibliotecaEnteros.h)
