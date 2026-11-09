//
// Created by cueva.r on 3/11/2026.
//

#ifndef POLIPLATOS_NODO_H
#define POLIPLATOS_NODO_H
#include "DetallaComanda.h"

class Nodo {
    private:
        DetallaComanda dato;
        Nodo *sig;

    public:
        Nodo();
        friend class Cola;
};


#endif //POLIPLATOS_NODO_H
