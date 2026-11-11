//
// Created by cueva.r on 21/10/2026.
//

#ifndef HERPLATOS_PLATOFONDO_H
#define HERPLATOS_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto {
private:
    int proteina;
public:
    PlatoFondo();
    ~PlatoFondo();
    PlatoFondo(PlatoFondo &orig);
    int get_proteina() const;
    void set_proteina(int proteina);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    char yosoy();
    Producto* asignapoli();
};


#endif //HERPLATOS_PLATOFONDO_H
