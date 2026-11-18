//
// Created by cueva.r on 17/11/2026.
//

#include "Libro.h"

Libro::Libro() {
    peso=0;
    paginas=0;
}

int Libro::get_paginas() const {
    return paginas;
}

void Libro::set_paginas(int paginas) {
    this->paginas = paginas;
}

double Libro::get_peso() const {
    return peso;
}

void Libro::set_peso(double peso) {
    this->peso = peso;
}

string Libro::get_nombre() const {
    return nombre;
}

void Libro::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

// Boletin de Arqueologia PUCP,52,9.25

void Libro::leelibro(ifstream &arch) {
    char c;
    getline(arch,nombre,',');
    if (arch.eof()) return;
    arch>>paginas>>c>>peso;
    arch.get();
}

