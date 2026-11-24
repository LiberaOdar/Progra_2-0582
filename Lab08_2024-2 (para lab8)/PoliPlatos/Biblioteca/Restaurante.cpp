//
// Created by cueva.r on 28/10/2026.
//
#include <iostream>
#include "Restaurante.h"

using namespace std;

Restaurante::Restaurante() {
    comandas=nullptr;
    numcom=0;
}

Restaurante::~Restaurante() {
    if (comandas!=nullptr)
        delete []comandas;
}

int Restaurante::get_numcom() const {
    return numcom;
}

void Restaurante::set_numcom(int numcom) {
    this->numcom = numcom;
}

void Restaurante::carga() {
    int id;
    DetallaComanda buffer[150];
    ifstream arch("comandas2.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
        arch >> id;
        if (arch.eof())break;
        arch.get();
        buffer[numcom].asignatipo(id,arch);
        cout << buffer[numcom].eles()<<endl;
        numcom++;
    }
    comandas=new DetallaComanda[numcom+1];
    // for (int i=0;i<numcom;i++)
    //     comandas[i]=buffer[i];

}
