//
// Created by cueva on 17/11/2026.
//

#include "Paquete.h"

Paquete::Paquete() {
    distancia=0;
}

int Paquete::get_cantidad() const {
    return cantidad;
}

void Paquete::set_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

string Paquete::get_codigo() const {
    return codigo;
}

void Paquete::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Paquete::get_distancia() const {
    return distancia;
}

void Paquete::set_distancia(double distancia) {
    this->distancia = distancia;
}
// P001,90,2,1
void Paquete::lee(ifstream &arch) {
    char c;
    getline(arch,codigo,',');
    arch>>distancia>>c>>cantidad>>c;
}

void Paquete::imprimir(ofstream &arch,double temp,bool urg ) {
    arch<<"Codigo:     "<<codigo<<endl;
    arch<<"Distancia:  "<<distancia<<endl;
    if (temp!=INT_MAX)
        arch<<"Temperatura:  "<<temp<<endl;
    else
        if (urg)
            arch<<"Urgente"<<endl;
        else
            arch<<"Estandar"<<endl;
    for (auto &v:vpila)
        v.imprimeproductos(arch);

}

void Paquete::cargapila(Producto &prod) {
    vpila.push_back(prod);
}
