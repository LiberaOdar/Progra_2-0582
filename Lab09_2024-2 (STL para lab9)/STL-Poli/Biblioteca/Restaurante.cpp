//
// Created by cueva.r on 28/10/2026.
//
#include <iostream>
#include "Restaurante.h"

#include <algorithm>

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
        vcomandas.push_back(aux);
    }

}



void Restaurante::descarga() {
    sort(vcomandas.begin(), vcomandas.end(),DetallaComanda::compara);
    ofstream arch("reporte.txt", ios::out);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
   for (int i = 0; i < vcomandas.size(); i++) {
       vcomandas[i].imprimecomanda(arch);
       arch << endl;
   }

}