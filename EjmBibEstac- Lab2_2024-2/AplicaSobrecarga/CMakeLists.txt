cmake_minimum_required(VERSION 4.2)
project(AplicaSobrecarga)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicaSobrecarga main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(AplicaSobrecarga PRIVATE SobreEstatica)