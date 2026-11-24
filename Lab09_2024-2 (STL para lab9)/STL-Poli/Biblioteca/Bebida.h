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
    Bebida(const Bebida&);
    void set_tamano(const char *tamano);
    void get_tamano(char *tamano);
    void lee(ifstream &);
    void imprime(ofstream &);
    char yosoy();
    Producto*asignapoli();
};


#endif //HERPLATOS_BEBIDA_H
