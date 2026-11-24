//
// Created by Erasmo on 10/06/25.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Drone.hpp"

using namespace std;

Drone::Drone() {
    id = nullptr;
    ubicacion = nullptr;
    capacidad = 0;

}
Drone::~Drone(){
    delete id;
    delete ubicacion;
}


void Drone::leer(ifstream &input) {
//Velocidad,DV001,Avenida G,5,60
    char buffer[60];
    input.getline(buffer, 20, ',');
    setId(buffer);
    input.getline(buffer, 60, ',');
    setUbicacion(buffer);
    input >> capacidad;
    input.get();
}

void Drone::getId(char *_id) const {
    if (this->id == nullptr) _id[0] = '\0';
    else strcpy(_id, this->id);
}

void Drone::setId(const char *_id) {
    if (this->id != nullptr) delete this->id;
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
}

void Drone::getUbicacion(char *_zona) const {
    if (ubicacion == nullptr) _zona[0] = '\0';
    else strcpy(_zona, ubicacion);
}

void Drone::setUbicacion(const char *_zona) {
    if (this->ubicacion != nullptr) delete this->ubicacion;
    this->ubicacion = new char[strlen(_zona) + 1];
    strcpy(this->ubicacion, _zona);
}

int Drone::getCapacidad() const {
    return capacidad;
}

void Drone::setCapacidad(int _capacidad) {
    capacidad = _capacidad;
}

void Drone::imprimir(ofstream &output) const {
    output << setw(10) << id << setw(10) << ubicacion << setw(5) << capacidad;
}


