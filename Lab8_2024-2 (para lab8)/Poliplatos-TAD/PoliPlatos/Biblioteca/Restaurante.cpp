//
// Created by cueva.r on 28/10/2026.
//
#include <iostream>
#include "Restaurante.h"

using namespace std;

Restaurante::Restaurante() {

}


void Restaurante::carga() {
    int id;
    ifstream arch("comandas2.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
        arch >> id;
        if (arch.eof())break;
        arch.get();
        DetallaComanda aux;
        aux.asignatipo(id,arch);
        Ccommanda.encola(aux);
    }

}

void Restaurante::descarga() {
    DetallaComanda aux;
    Ccommanda.desencola(aux);
}