cmake_minimum_required(VERSION 4.2)
project(ListEmpaques)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListEmpaques main.cpp
        Biblioteca/Producto.cpp
        Biblioteca/Producto.h
        Biblioteca/Paquete.cpp
        Biblioteca/Paquete.h
        Biblioteca/Empresa.cpp
        Biblioteca/Empresa.h
        Biblioteca/Estandar.cpp
        Biblioteca/Estandar.h
        Biblioteca/Especial.cpp
        Biblioteca/Especial.h)
