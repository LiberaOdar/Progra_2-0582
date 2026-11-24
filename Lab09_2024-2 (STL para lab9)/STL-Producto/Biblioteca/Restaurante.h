//
// Created by cueva.r on 10/11/2026.
//

#ifndef STL_PRODUCTO_RESTAURANTE_H
#define STL_PRODUCTO_RESTAURANTE_H
#include <list>
#include <map>
#include "Producto.h"


class Restaurante {
    private:
        list<Producto> lproductos;
        map<string, Producto> mproductos;
    public:
        Restaurante();
        void carga();
        void mostrar();
};


#endif //STL_PRODUCTO_RESTAURANTE_H
