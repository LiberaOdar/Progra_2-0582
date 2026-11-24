//
// Created by cueva.r on 30/09/2026.
//

#include "Cliente.h"
#include <iomanip>
#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;


Cliente::Cliente() {
    dni=0;
    nombre=nullptr;
    distrito=nullptr;
    descuento=0;
    totalpagado=0;
}

Cliente::~Cliente() {
    if (nombre!=nullptr ) delete nombre;
    if (distrito!=nullptr) delete distrito;
}

Cliente::Cliente(const Cliente &orig) {
    nombre=nullptr;
    distrito=nullptr;
    *this=orig;
}

int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(int dni) {
    this->dni = dni;
}

double Cliente::get_descuento() const {
    return descuento;
}

void Cliente::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::get_totalpagado() const {
    return totalpagado;
}

void Cliente::set_totalpagado(double totalpagado) {
    this->totalpagado = totalpagado;
}

void Cliente::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr)
        delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void Cliente::set_distrito(const char *distrito) {
    if (this->distrito!=nullptr) delete this->distrito;
    this->distrito = new char[strlen(distrito)+1];
    strcpy(this->distrito, distrito);
}

void Cliente::get_distrito(char *distrito) {
    if (this->distrito!=nullptr)
        strcpy(distrito, this->distrito);
}


void Cliente::asigna(Cliente &aux) {
    dni=aux.dni;
    descuento=aux.descuento;
    totalpagado=aux.totalpagado;
    set_nombre(aux.nombre);
    set_distrito(aux.distrito);
}

void Cliente::operator=(const Cliente &orig) {
    dni=orig.dni;
    descuento=orig.descuento;
    totalpagado=orig.totalpagado;
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    if (orig.distrito!=nullptr)
        set_distrito(orig.distrito);
}

void Cliente::libera() {
    if (nombre!=nullptr ) delete nombre;
    if (distrito!=nullptr) delete distrito;
    dni=0;
    nombre=nullptr;
    distrito=nullptr;
    descuento=0;
    totalpagado=0;
}

void Cliente::imprime_cliente(ofstream &arch) {
    arch << setw(10) << dni;
    arch << setw(50)<< nombre;
    arch << setw(50)<< distrito;
    arch << setw(10)<< descuento;
    arch << setw(10)<< totalpagado << endl;

}

void operator<<(ofstream &arch, Cliente &clie) {
    char nom[100],dist[100];

    arch << setw(10) << clie.get_dni();
    clie.get_nombre(nom);
    arch << setw(50)<< nom;
    clie.get_distrito(dist);
    arch << setw(50)<< dist;
    arch << setw(10)<< clie.get_descuento();
    arch << setw(10)<< clie.get_descuento() << endl;


}

//90367684,CORONEL CHUMPITAZ HELI,Villa Maria del Triunfo,S,13.04%
void Cliente::lee_cliente(ifstream &arch) {
    char cad[100],c;
    arch >> dni;
    if (arch.eof())return;
    arch.get();
    arch.getline(cad,100,',');
    set_nombre(cad);
    arch.getline(cad,100,',');
    set_distrito(cad);
    arch>>c;
    if (c=='S') {
        arch.get();
        arch>>descuento>>c;
    }
}
//90367684,CORONEL CHUMPITAZ HELI,Villa Maria del Triunfo,S,13.04%
void operator>>(ifstream &arch, Cliente &clie) {
    char nom[100],dist[100],c;
    int dni;
    double descuento;
    arch >> dni;
    if (arch.eof())return;
    arch.get();
    arch.getline(nom,100,',');
    arch.getline(dist,100,',');
    arch>>c;
    if (c=='S') {
        arch.get();
        arch>>descuento>>c;
        clie.set_descuento(descuento);
    }
    clie.set_dni(dni);
    clie.set_nombre(nom);
    clie.set_distrito(dist);
}

void Cliente::llamando(Cliente clie) {

    cout << "Que pasara";
}
