//
// Created by cueva.r on 20/10/2026.
//
#include "Entrada.h"
#include "Producto.h"
#include <cstring>
#include <iomanip>

using namespace std;

Entrada::Entrada() {
    picante=false;
}

Entrada::Entrada(Entrada &orig):Producto(orig) {
    picante=orig.picante;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}

void Entrada::lee(ifstream &arch) {
    char cad[100];

    Producto::lee(arch);
    arch.getline(cad,100);
    if (strcmp(cad,"picante")==0)
        picante=true;

}
void Entrada::imprime(ofstream &arch) {
    double precio;
    Producto::imprime(arch);
    if (picante)
        arch << setw(20) << "Picante";
    else
        arch << setw(20) << "Sin picante";
}

char Entrada::yosoy() {
    return 'E';
}

Producto* Entrada::asignapoli() {
    return new Entrada(*this);
}

