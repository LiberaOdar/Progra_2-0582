//
// Created by cueva on 17/11/2026.
//

#include "Especial.h"

Especial::Especial() {

}

void Especial::lee(ifstream &arch) {
    Paquete::lee(arch);
    arch>>temperatura;
    arch.get();
}
void Especial::imprimir(ofstream &arch,double temp,bool urg) {
    Paquete::imprimir(arch,temperatura,false);
}