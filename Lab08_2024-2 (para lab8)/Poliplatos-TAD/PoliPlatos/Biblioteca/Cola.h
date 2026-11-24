//
// Created by cueva.r on 3/11/2026.
//

#ifndef POLIPLATOS_COLA_H
#define POLIPLATOS_COLA_H
#include "Nodo.h"


class Cola {
    private:
        int longitud;
        Nodo*cabeza;
        Nodo *cola;
    public:
        Cola();
        void encola(DetallaComanda&);
        void desencola(DetallaComanda&);

};


#endif //POLIPLATOS_COLA_H
