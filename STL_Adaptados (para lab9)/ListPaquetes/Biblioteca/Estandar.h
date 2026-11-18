//
// Created by cueva on 17/11/2026.
//

#ifndef LISTEMPAQUES_ESTANDAR_H
#define LISTEMPAQUES_ESTANDAR_H
#include "Paquete.h"
#include <fstream>

using namespace std;

class Estandar:public Paquete {
    private:
        bool urgente;
    public:
        Estandar();
        void lee(ifstream &);
        void imprimir(ofstream &,double,bool);
};


#endif //LISTEMPAQUES_ESTANDAR_H
