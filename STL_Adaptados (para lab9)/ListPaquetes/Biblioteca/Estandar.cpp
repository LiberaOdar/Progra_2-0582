//
// Created by cueva on 17/11/2026.
//

#include "Estandar.h"

Estandar::Estandar() {

}

void Estandar::lee(ifstream &arch) {
    int num;
    Paquete::lee(arch);
    arch >> num;
    if (num==1)
        urgente = true;
    else
        urgente = false;
    arch.get();
}

void Estandar::imprimir(ofstream &arch,double temp, bool urg) {
    Paquete::imprimir(arch,INT_MAX,urgente);
}