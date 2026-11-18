//
// Created by cueva.r on 17/11/2026.
//

#include "Estante.h"

char Estante::get_tipo() const {
    return tipo;
}

void Estante::set_tipo(char tipo) {
    this->tipo = tipo;
}

int Estante::get_id() const {
    return id;
}

void Estante::set_id(int id) {
    this->id = id;
}

double Estante::get_capacidad() const {
    return capacidad;
}

void Estante::set_capacidad(double capacidad) {
    this->capacidad = capacidad;
}

Estante::Estante() {
    id=0;
    capacidad=0;
}
// H,1,20
void Estante::leestante(ifstream &arch) {
    char c;
    arch >> tipo;
    if (arch.eof())return;
    arch >> c>>id>>c>>capacidad;
    arch.get();
}

bool Estante::operator<(const Estante &orig)const {
    return id<orig.id;
}
