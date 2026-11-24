//
// Created by cueva.r on 10/11/2026.
//
#include <iostream>
#include "Restaurante.h"

using namespace std;

Restaurante::Restaurante() {

}

void Restaurante::carga() {
    ifstream arch("productos.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
        Producto aux;
        if (not aux.lee(arch)) break;
        lproductos.push_back(aux);
        //ahora con mapa
        mproductos[aux.get_codigo()]=aux;
    }
}

void Restaurante::mostrar() {
    ofstream arch("Reporte.txt", ios::out);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    for (list<Producto>::iterator it=lproductos.begin();it!=lproductos.end();
        it++)
        it->imprime(arch);

}
