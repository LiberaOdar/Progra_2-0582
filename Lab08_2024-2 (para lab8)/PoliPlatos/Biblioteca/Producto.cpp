//
// Created by cueva.r on 20/10/2026.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    nombre=nullptr;
    precio=0;
}
Producto::~Producto() {
    if (nombre!=nullptr)
        delete nombre;
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}
void Producto::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr)
        delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Producto::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

// Cafe,2,
void Producto::lee(ifstream &arch) {
    char cad[100];
    arch.getline(cad,100,',');
    set_nombre(cad);
    arch >> precio;
    arch.get();
}

void Producto::imprimeproducto(ofstream &arch,double &monto) {
    arch <<setw(50)<< nombre << endl;
    monto = precio;
}