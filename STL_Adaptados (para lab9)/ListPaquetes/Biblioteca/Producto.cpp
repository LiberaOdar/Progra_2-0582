//
// Created by cueva on 17/11/2026.
//
#include <iomanip>
#include "Producto.h"

Producto::Producto() {
    peso=0;
    valor=0;
}

string Producto::get_codigo() const {
    return codigo;
}

void Producto::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Producto::get_nombre() const {
    return nombre;
}

void Producto::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

double Producto::get_peso() const {
    return peso;
}

void Producto::set_peso(double peso) {
    this->peso = peso;
}

double Producto::get_valor() const {
    return valor;
}

void Producto::set_valor(double valor) {
    this->valor = valor;
}
//P001,PR001,Laptop,2.5,3500
//P001,PR002,Mouse,0.3,120

void Producto::leeproductos(ifstream &arch) {
    char c;
    getline(arch,codigo,',');
    getline(arch,nombre,',');
    arch>>peso>>c>>valor;
    arch.get();
}

void Producto::imprimeproductos(ofstream &arch) {
    arch<<setw(5)<< codigo<<setw(20) << nombre;
    arch <<setw(5)<< peso<<setw(5) << valor<<endl;
}