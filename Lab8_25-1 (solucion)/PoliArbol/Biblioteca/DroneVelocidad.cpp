//
// Created by Erasmo on 11/06/25.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include "DroneVelocidad.hpp"
using namespace std;

void DroneVelocidad::leer(ifstream &input) {
//Velocidad,DV696,Avenida A,5,60
    Drone::leer(input);
    input>>velocidad_maxima_permitida;
    input.get();
}

void DroneVelocidad::imprimir(ofstream &output) const{
    Drone::imprimir(output);
    output<<setw(10)<<velocidad_maxima_permitida<<endl;

}

int DroneVelocidad::getVelocidadMaximaPermitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::setVelocidadMaximaPermitida(int velocidadMaximaPermitida) {
    velocidad_maxima_permitida = velocidadMaximaPermitida;
}

char DroneVelocidad::gettipo(){
    return 'V';
}