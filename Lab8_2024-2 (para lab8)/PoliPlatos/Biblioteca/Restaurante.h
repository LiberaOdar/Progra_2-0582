//
// Created by cueva.r on 28/10/2026.
//

#ifndef POLIPLATOS_RESTAURANTE_H
#define POLIPLATOS_RESTAURANTE_H
#include "DetallaComanda.h"


class Restaurante {
    private:
        DetallaComanda *comandas;
        int numcom;
    public:
        Restaurante();
        ~Restaurante();
        int get_numcom() const;
        void set_numcom(int numcom);
        void carga();
};


#endif //POLIPLATOS_RESTAURANTE_H
