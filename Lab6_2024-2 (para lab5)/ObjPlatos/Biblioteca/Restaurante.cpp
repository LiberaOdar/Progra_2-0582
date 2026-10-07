//
// Created by cueva.r on 6/10/2026.
//

#include "Restaurante.h"
#include <iostream>

using namespace std;

Restaurante::Restaurante() {
    cantDeClientes=0;
    cantDePlatos=0;
}

void Restaurante::cargaclientes(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        //lectura directa
        //clientes[cantDeClientes].lee_cliente(arch);
        //ahora lectura usando auxiliar
        Cliente aux;
        aux.lee_cliente(arch);
        if (arch.eof()) break;
        clientes[cantDeClientes].asigna(aux);
        cantDeClientes++;
    }

}
