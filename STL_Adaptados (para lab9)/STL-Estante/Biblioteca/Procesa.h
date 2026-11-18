//
// Created by cueva.r on 17/11/2026.
//

#ifndef STL_ESTANTE_PROCESA_H
#define STL_ESTANTE_PROCESA_H
#include "Estante.h"
#include "Libro.h"
#include <vector>
#include <map>

class Procesa {
    public:
        Procesa();
        void carga();
    private:
        map<Estante,vector<Libro>>mestante;
        void cargalibros();
};


#endif //STL_ESTANTE_PROCESA_H
