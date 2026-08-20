cmake_minimum_required(VERSION 4.2)
project(SobrecargaDeAlummnos)

set(CMAKE_CXX_STANDARD 20)

add_executable(SobrecargaDeAlummnos main.cpp
        Biblioteca/Sobrecarga.cpp
        Biblioteca/Sobrecarga.h
)
