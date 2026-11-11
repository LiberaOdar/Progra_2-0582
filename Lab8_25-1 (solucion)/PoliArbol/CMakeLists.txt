cmake_minimum_required(VERSION 4.2)
project(PoliArbol)

set(CMAKE_CXX_STANDARD 20)

add_executable(PoliArbol main.cpp
        Biblioteca/Central.cpp
        Biblioteca/Arbol.cpp
        Biblioteca/DroneEstacionamiento.cpp
        Biblioteca/DroneSemaforo.cpp
        Biblioteca/DroneVelocidad.cpp
        Biblioteca/Nodo.cpp
        Biblioteca/Drone.cpp)
