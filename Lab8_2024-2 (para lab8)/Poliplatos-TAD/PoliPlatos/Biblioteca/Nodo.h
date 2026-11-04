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
        friend class Cola;
    public:
        Nodo();

};


#endif //POLIPLATOS_NODO_H
