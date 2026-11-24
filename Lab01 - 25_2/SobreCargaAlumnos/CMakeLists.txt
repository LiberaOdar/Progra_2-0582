cmake_minimum_required(VERSION 4.2)
project(SobreCargaAlumnos)

set(CMAKE_CXX_STANDARD 20)

add_executable(SobreCargaAlumnos main.cpp
        Bibliotecas/Sobrecargas.cpp
        Bibliotecas/Sobrecargas.h)
