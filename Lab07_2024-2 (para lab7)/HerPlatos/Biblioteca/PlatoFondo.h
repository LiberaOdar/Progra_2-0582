//
// Created by cueva.r on 21/10/2026.
//

#ifndef HERPLATOS_PLATOFONDO_H
#define HERPLATOS_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto {
private:
    int *proteina;
public:
    PlatoFondo();
    ~PlatoFondo();
    void leeplato(ifstream &arch);
    void imprimeplato(ofstream &arch);
};


#endif //HERPLATOS_PLATOFONDO_H
