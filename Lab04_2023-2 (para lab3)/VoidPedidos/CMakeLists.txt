cmake_minimum_required(VERSION 4.0)
project(VoidPedidos)

set(CMAKE_CXX_STANDARD 20)

add_executable(VoidPedidos main.cpp
        MiBiblioteca/PunterosGenericos.cpp
        MiBiblioteca/PunterosGenericos.h)
