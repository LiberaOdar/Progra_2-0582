//
// Created by Erasmo on 11/06/25.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include "DroneEstacionamiento.hpp"

using namespace std;

void DroneEstacionamiento::leer(ifstream &input) {
//Estacionamiento,DE987,Avenida C,15,false
    Drone::leer(input);
    char buffer[10];
    input.getline(buffer, 10);
    if(strcmp(buffer, "true")==0)
        zona_carga = 1;
    else
        zona_carga = 0;

}

void DroneEstacionamiento::imprimir(ofstream &output) const {
    Drone::imprimir(output);
    output<<setw(10)<<zona_carga<<endl;

}

int DroneEstacionamiento::getZonaCarga() const {
    return zona_carga;
}

void DroneEstacionamiento::setZonaCarga(int zonaCarga) {
    zona_carga = zonaCarga;
}

char DroneEstacionamiento::gettipo(){
    return 'E';
}

void DroneEstacionamiento::cambia(int valor){
    zona_carga=valor;
}
