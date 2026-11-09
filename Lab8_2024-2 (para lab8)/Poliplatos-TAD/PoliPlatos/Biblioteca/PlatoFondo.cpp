//
// Created by cueva.r on 21/10/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina=0;
}
PlatoFondo::~PlatoFondo() {

}
PlatoFondo::PlatoFondo(PlatoFondo &orig):Producto(orig) {
    proteina=orig.proteina;
}


int PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}

void PlatoFondo::lee(ifstream &arch) {
    Producto::lee(arch);
    arch >> proteina;
}

void PlatoFondo::imprimeplato(ofstream &arch) {
    double precio;
    imprimeproducto(arch,precio);
    
}

char PlatoFondo::yosoy() {
    return 'P';
}

Producto *PlatoFondo::asignapoli() {
    return new PlatoFondo(*this);
}
