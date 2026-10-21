//
// Created by cueva.r on 21/10/2026.
//

#include "Restaurante.h"

#include <iostream>

Restaurante::Restaurante() {
    cantidad_comandas=0;
}

int Restaurante::get_cantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::set_cantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}
// 142,B,Cafe,2,grande
void Restaurante::cargar_comandas() {
    ifstream arch("comandas.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
                    

    }

}
