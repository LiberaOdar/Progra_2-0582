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

Producto::Producto(const Producto &orig) {
    precio = orig.precio;
    codigo =orig.codigo;
    nombre=nullptr;
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
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

//892XJ,Tallarines Rojos,15.0
bool Producto::lee(ifstream &arch) {
    char cad[100];
    getline(arch,codigo,',');
    if (arch.eof())  return false;
    arch.getline(cad,100,',');
    set_nombre(cad);
    arch >> precio;
    arch.get();
    return true;
}

void Producto::imprime(ofstream &arch) {
    arch <<setw(10)<<codigo<< setw(40)<< nombre <<setw(10)<<precio<<endl;
}

string Producto::get_codigo() const {
    return codigo;
}

void Producto::set_codigo(const string &codigo) {
    this->codigo = codigo;
}
