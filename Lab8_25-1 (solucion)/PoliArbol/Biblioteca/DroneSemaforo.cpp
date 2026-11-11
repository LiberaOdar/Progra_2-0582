//
// Created by Erasmo on 11/06/25.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "DroneSemaforo.hpp"

using namespace std;

void DroneSemaforo::leer(ifstream &input) {
//Semaforo,DS339,Avenida E,10,true
    Drone::leer(input);
    char buffer[10];
    input.getline(buffer, 10, '\n');
    if(strcmp(buffer, "true")==0)
        ConCamaraRoja = 1;
    else
        ConCamaraRoja = 0;
}

void DroneSemaforo::imprimir(ofstream &output) const{
    Drone::imprimir(output);
    output<<setw(10)<<ConCamaraRoja<<endl;

}

int DroneSemaforo::getConCamaraRoja() const {
    return ConCamaraRoja;
}

void DroneSemaforo::setConCamaraRoja(int conCamaraRoja) {
    ConCamaraRoja = conCamaraRoja;
}

char DroneSemaforo::gettipo(){
    return 'S';
}

void DroneSemaforo::cambia(int valor){
    ConCamaraRoja=valor;
}