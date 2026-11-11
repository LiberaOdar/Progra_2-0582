//
// Created by cueva.r on 20/10/2026.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Bebida.h"

using namespace std;

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano!=nullptr)
        delete tamano;
}

Bebida::Bebida(const Bebida &orig):Producto(orig){
    tamano=nullptr;
    if (orig.tamano!=nullptr)
        set_tamano(orig.tamano);
}


void Bebida::set_tamano(const char *tamano) {
    if (this->tamano!=nullptr)
        delete this->tamano;
    this->tamano = new char[strlen(tamano)+1];
    strcpy(this->tamano, tamano);
}

void Bebida::get_tamano(char *tamano) {
    if (this->tamano!=nullptr)
        strcpy(tamano, this->tamano);
}
// grande
void Bebida::lee(ifstream &arch) {
    char cad[100];
    Producto::lee(arch);
    arch.getline(cad,100);
    set_tamano(cad);
}

void Bebida::imprime(ofstream &arch) {
    Producto::imprime(arch);
    arch <<setw(20)<< tamano;
}

char Bebida::yosoy() {
    return 'B';
}

Producto *Bebida::asignapoli() {
    return new Bebida(*this);
}

