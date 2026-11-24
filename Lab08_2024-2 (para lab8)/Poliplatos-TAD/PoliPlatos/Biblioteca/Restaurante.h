//
// Created by cueva.r on 28/10/2026.
//

#ifndef POLIPLATOS_RESTAURANTE_H
#define POLIPLATOS_RESTAURANTE_H
#include "Cola.h"
#include "DetallaComanda.h"


class Restaurante {
    private:
        // DetallaComanda *comandas;
        // int numcom;
        Cola Ccommanda;
    public:
        Restaurante();
        void carga();
        void descarga();
};


#endif //POLIPLATOS_RESTAURANTE_H
