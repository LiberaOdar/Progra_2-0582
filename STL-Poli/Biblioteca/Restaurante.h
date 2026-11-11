//
// Created by cueva.r on 28/10/2026.
//

#ifndef POLIPLATOS_RESTAURANTE_H
#define POLIPLATOS_RESTAURANTE_H
#include <vector>
#include "DetallaComanda.h"
using namespace std;

class Restaurante {
    private:
        vector<DetallaComanda>vcomandas;

    public:
        Restaurante();
        void carga();
        void descarga();

};


#endif //POLIPLATOS_RESTAURANTE_H
