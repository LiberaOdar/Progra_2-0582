cmake_minimum_required(VERSION 4.2)
project(SobreCarga)

set(CMAKE_CXX_STANDARD 20)

add_executable(SobreCarga main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
)
