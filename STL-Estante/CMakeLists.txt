cmake_minimum_required(VERSION 4.2)
project(STL_Estante)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_Estante main.cpp
        Biblioteca/Procesa.cpp
        Biblioteca/Procesa.h
        Biblioteca/Estante.cpp
        Biblioteca/Estante.h
        Biblioteca/Libro.cpp
        Biblioteca/Libro.h)
