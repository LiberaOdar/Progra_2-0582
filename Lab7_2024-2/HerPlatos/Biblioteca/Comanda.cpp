//
// Created by cueva.r on 21/10/2026.
//

#include "Comanda.h"

Comanda::Comanda() {
    id=0;
    cantidad_entradas=0;
    cantidad_bebidas=0;
    cantidad_platos_fondo=0;
    hora_atencion=0;
    tiempo_preparcion=0;
    total=0;
}

int Comanda::get_id() const {
    return id;
}
void Comanda::set_id(int id) {
    this->id = id;
}
int Comanda::get_cantidad_entradas() const {
    return cantidad_entradas;
}
void Comanda::set_cantidad_entradas(int cantidad_entradas) {
    this->cantidad_entradas = cantidad_entradas;
}
int Comanda::get_cantidad_bebidas() const {
    return cantidad_bebidas;
}
void Comanda::set_cantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}
int Comanda::get_cantidad_platos_fondo() const {
    return cantidad_platos_fondo;
}
void Comanda::set_cantidad_platos_fondo(int cantidad_platos_fondo) {
    this->cantidad_platos_fondo = cantidad_platos_fondo;
}
int Comanda::get_hora_atencion() const {
    return hora_atencion;
}
void Comanda::set_hora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}
int Comanda::get_tiempo_preparcion() const {
    return tiempo_preparcion;
}
void Comanda::set_tiempo_preparcion(int tiempo_preparcion) {
    this->tiempo_preparcion = tiempo_preparcion;
}
double Comanda::get_total() const {
    return total;
}
void Comanda::set_total(double total) {
    this->total = total;
}
