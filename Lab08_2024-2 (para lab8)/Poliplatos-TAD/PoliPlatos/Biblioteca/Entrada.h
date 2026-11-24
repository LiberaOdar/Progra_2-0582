//
// Created by cueva.r on 20/10/2026.
//

#ifndef HERPLATOS_ENTRADA_H
#define HERPLATOS_ENTRADA_H
#include "Producto.h"


class Entrada:public Producto {
private:
    bool picante;
public:
    Entrada();
    Entrada(Entrada &orig);
    bool is_picante() const;
    void set_picante(bool picante);
    void lee(ifstream &arch);
    void imprimeentrada(ofstream &arch);
    char yosoy();
    Producto *asignapoli();
};


#endif //HERPLATOS_ENTRADA_H
