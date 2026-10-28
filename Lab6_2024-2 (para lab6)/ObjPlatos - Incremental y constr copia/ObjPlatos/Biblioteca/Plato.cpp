//
// Created by cueva.r on 6/10/2026.
//
#include <cstring>
#include "Plato.h"

using namespace std;

Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    precio=0;
    categoria=nullptr;
    preparados=0;
    descuento=0;
    atendidos=0;
    noAtendidos=0;
    totalEsperado=0;
    totalBruto=0;
    totalNeto=0;
}
Plato::~Plato() {
    if (codigo!=nullptr)
        delete codigo;
    if (nombre!=nullptr)
        delete nombre;
    if (categoria!=nullptr)
        delete categoria;
}

void Plato::operator=(Plato &orig) {
    if (orig.codigo!=nullptr)
        set_codigo(orig.codigo);
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    precio=orig.precio;
    if (orig.categoria!=nullptr)
        set_categoria(orig.categoria);
    preparados=orig.preparados;
    descuento=orig.descuento;
    atendidos=orig.atendidos;
    noAtendidos=orig.noAtendidos;
    totalEsperado=orig.totalEsperado;
    totalBruto=orig.totalBruto;
    totalNeto=orig.totalNeto;
}

double Plato::get_precio() const {
    return precio;
}

void Plato::set_precio(double precio) {
    this->precio = precio;
}

int Plato::get_preparados() const {
    return preparados;
}

void Plato::set_preparados(int preparados) {
    this->preparados = preparados;
}

double Plato::get_descuento() const {
    return descuento;
}

void Plato::set_descuento(double descuento) {
    this->descuento = descuento;
}

int Plato::get_atendidos() const {
    return atendidos;
}

void Plato::set_atendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atendidos() const {
    return noAtendidos;
}

void Plato::set_no_atendidos(int no_atendidos) {
    noAtendidos = no_atendidos;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}

void Plato::set_total_esperado(double total_esperado) {
    totalEsperado = total_esperado;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}

void Plato::set_total_bruto(double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_total_neto() const {
    return totalNeto;
}

void Plato::set_total_neto(double total_neto) {
    totalNeto = total_neto;
}

void Plato::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr)
        delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Plato::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void Plato::set_codigo(const char *codigo) {
    if (this->codigo!=nullptr)
        delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void Plato::get_codigo(char *codigo) {
    if (this->codigo!=nullptr)
        strcpy(codigo, this->codigo);
}

void Plato::set_categoria(const char *categoria) {
    if (this->categoria!=nullptr)
        delete this->categoria;
    this->categoria = new char[strlen(categoria)+1];
    strcpy(this->categoria, categoria);
}

void Plato::get_categoria(char *categoria) {
    if (this->categoria!=nullptr)
        strcpy(categoria, this->categoria);
}

void Plato::leeplato(ifstream &arch) {
    char cad[100],c;

    arch.getline(cad, 100,',');
    if (arch.eof())return;
    set_codigo(cad);
    arch.getline(cad, 100,',');
    set_nombre(cad);
    arch >> precio >> c;
    arch.getline(cad, 100,',');
    set_categoria(cad);
    arch >> preparados;
    if (arch.get()==',') {
        arch >> descuento >> c;
        arch.get();
    }
}

void operator>>(ifstream &arch, Plato &plato) {
    char cad[100],c;
    double precio,desc;
    int num;
    arch.getline(cad, 100,',');
    if (arch.eof())return;
    plato.set_codigo(cad);
    arch.getline(cad, 100,',');
    plato.set_nombre(cad);
    arch >> precio >> c;
    plato.set_precio(precio);
    arch.getline(cad, 100,',');
    plato.set_categoria(cad);
    arch >> num;
    plato.set_preparados(num);
    if (arch.get()==',') {
        arch >> desc >> c;
        arch.get();
        plato.set_descuento(desc);
    }
}
