//
// Created by cueva.r on 20/10/2026.
//
#include <iostream>
#include <cstring>
#include "Bebida.h"

using namespace std;

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano!=nullptr)
        delete tamano;
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
void Bebida::leebebida(ifstream &arch) {
    char cad[100];
    leeproducto(arch);
    arch.getline(cad,100);
    set_tamano(cad);
}
