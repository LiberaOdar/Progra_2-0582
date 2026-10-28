cmake_minimum_required(VERSION 4.2)
project(PoliPlatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PoliPlatos main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Bebida.cpp
        Biblioteca/Entrada.cpp
        Biblioteca/PlatoFondo.cpp
        Biblioteca/DetallaComanda.cpp
        Biblioteca/DetallaComanda.h
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
