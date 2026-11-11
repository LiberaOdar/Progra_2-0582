//
// Created by cueva.r on 21/10/2026.
//
#include "PlatoFondo.h"
#include "Producto.h"

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

void PlatoFondo::imprime(ofstream &arch) {
    Producto::imprime(arch);
    if (proteina==1)
        arch << " Pollo";
    if (proteina==2)
        arch << " Carne";
    if (proteina==3)
        arch << " Pescado";
    if (proteina==4)
        arch << " Lacteos";
    
}

char PlatoFondo::yosoy() {
    return 'P';
}

Producto *PlatoFondo::asignapoli() {
    return new PlatoFondo(*this);
}
