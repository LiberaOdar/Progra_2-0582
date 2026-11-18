//
// Created by cueva on 17/11/2026.
//

#ifndef LISTEMPAQUES_ESPECIAL_H
#define LISTEMPAQUES_ESPECIAL_H
#include "Paquete.h"
#include <fstream>

using namespace std;

class Especial:public Paquete {
    private:
        double temperatura;
    public:
        Especial();
        void lee(ifstream &);
        void imprimir(ofstream &,double,bool);
};


#endif //LISTEMPAQUES_ESPECIAL_H
