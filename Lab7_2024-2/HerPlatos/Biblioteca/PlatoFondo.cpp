//
// Created by cueva.r on 21/10/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina=new int[4]{};
}
PlatoFondo::~PlatoFondo() {
    if (proteina!=nullptr) delete proteina;
}

void PlatoFondo::leeplato(ifstream &arch) {
    leeproducto(arch);
    for (int i=0; i<4; i++) {
        arch>>proteina[i];
        arch.get();
    }
}
