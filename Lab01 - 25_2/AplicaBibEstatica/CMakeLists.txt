cmake_minimum_required(VERSION 4.2)
project(AplicaBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicaBibEstatica main.cpp
        Biblioteca/Funciones.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Biblioteca")
target_link_libraries(AplicaBibEstatica PRIVATE Sobrecargas)

