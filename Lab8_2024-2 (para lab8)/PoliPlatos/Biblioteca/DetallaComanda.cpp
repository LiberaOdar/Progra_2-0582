//
// Created by cueva.r on 28/10/2026.
//

#include "DetallaComanda.h"

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

DetallaComanda::DetallaComanda() {
    id=0;
    pedido=nullptr;
}

DetallaComanda::~DetallaComanda() {
    if (pedido!=nullptr)
        delete pedido;
}

int DetallaComanda::get_id() const {
    return id;
}

void DetallaComanda::set_id(int id) {
    this->id = id;
}

void DetallaComanda::asignatipo(int id,ifstream &arch) {
    char tipo;
    this->id=id;
    arch >> tipo;
    arch.get(); //coma de la Srta Odar
    if (tipo=='E')
        pedido=new Entrada;
    if (tipo=='B')
        pedido=new Bebida;
    if (tipo=='P')
        pedido=new PlatoFondo;
    pedido->lee(arch);
}

void DetallaComanda::operator=(DetallaComanda &orig) {
    id=orig.id;
    pedido=orig.pedido;
}

char DetallaComanda::eles() {
    return pedido->yosoy();
}
