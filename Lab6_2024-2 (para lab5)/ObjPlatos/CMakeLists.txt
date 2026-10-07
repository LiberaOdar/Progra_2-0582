cmake_minimum_required(VERSION 4.2)
project(ObjPlatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ObjPlatos main.cpp
        Biblioteca/Cliente.cpp
        Biblioteca/Cliente.h
        Biblioteca/Plato.cpp
        Biblioteca/Plato.h
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
