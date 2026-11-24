cmake_minimum_required(VERSION 4.2)
project(STL_Producto)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_Producto main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
