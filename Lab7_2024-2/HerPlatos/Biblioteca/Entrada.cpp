//
// Created by cueva.r on 20/10/2026.
//

#include "Entrada.h"
#include <cstring>

using namespace std;

Entrada::Entrada() {
    picante=false;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}

void Entrada::leeentrada(ifstream &arch) {
    char cad[100];

    this->leeproducto(arch);
    arch.getline(cad,100);
    if (strcmp(cad,"picante")==0)
        picante=true;

}
