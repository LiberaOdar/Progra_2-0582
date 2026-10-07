//
// Created by cueva.r on 6/10/2026.
//

#include "Plato.h"

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
