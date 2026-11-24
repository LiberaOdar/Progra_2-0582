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
    int id;
    ifstream arch("comandas.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
        arch >> id;
        if (arch.eof()) break;
        arch.get();
        int pos=buscacomandas(id);
        if (pos==-1) {
            comandas[cantidad_comandas].cargapedido(id,arch);
            cantidad_comandas++;
        }
        else
            comandas[pos].cargapedido(id,arch);

    }

}

int Restaurante::buscacomandas(int id) {
    for (int i=0; i<cantidad_comandas; i++) {
        if (id==comandas[i].get_id())
            return i;
    }
    return -1;
}
