cmake_minimum_required(VERSION 4.2)
project(ListadeArreglos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListadeArreglos main.cpp
        Biblioteca/BibliotecaGenerica.cpp
        Biblioteca/BibliotecaGenerica.h
        Biblioteca/ListaconEnteros.cpp
        Biblioteca/ListaconEnteros.h
        Biblioteca/ListaconRegistros.cpp)
