cmake_minimum_required(VERSION 4.2)
project(STL_Poli)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_Poli main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/PlatoFondo.cpp
        Biblioteca/Entrada.cpp
        Biblioteca/DetallaComanda.cpp
        Biblioteca/Bebida.cpp
        Biblioteca/Restaurante.cpp)
