//
// Created by cueva.r on 20/10/2026.
//

#ifndef HERPLATOS_BEBIDA_H
#define HERPLATOS_BEBIDA_H
#include "Producto.h"

class Bebida: public Producto {
private:
    char *tamano;
public:
    Bebida();
    ~Bebida();
    void set_tamano(const char *tamano);
    void get_tamano(char *tamano);
    void leebebida(ifstream &);
};


#endif //HERPLATOS_BEBIDA_H
