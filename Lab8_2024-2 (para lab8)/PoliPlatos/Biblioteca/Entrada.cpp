//
// Created by cueva.r on 20/10/2026.
//

#include "Entrada.h"
#include <cstring>
#include <iomanip>

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

void Entrada::lee(ifstream &arch) {
    char cad[100];

    Producto::lee(arch);
    arch.getline(cad,100);
    if (strcmp(cad,"picante")==0)
        picante=true;

}
void Entrada::imprimeentrada(ofstream &arch) {
    double precio;
    imprimeproducto(arch,precio);
    if (picante)
        arch << setw(20) << "Picante";
    else
        arch << setw(20) << "Sin picante";
    arch <<setw(10)<< precio << endl;
}

char Entrada::yosoy() {
    return 'E';
}
