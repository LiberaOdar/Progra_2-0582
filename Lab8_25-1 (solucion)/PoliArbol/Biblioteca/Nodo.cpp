/* 
 * File:   Nodo.cpp
 * Author: cueva
 * 
 * Created on 18 de noviembre de 2022, 08:28 AM
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "Nodo.h"
#include "DroneVelocidad.hpp"
#include "DroneSemaforo.hpp"
#include "DroneEstacionamiento.hpp"

using namespace std;

Nodo::Nodo() {
    dron = nullptr;
    izq = nullptr;
    der = nullptr;
}

Nodo::Nodo(const Nodo& orig) {

}

Nodo::~Nodo() {
    delete dron;
}

void Nodo::asignamemoria(char *tipo){
    if(strcmp(tipo,"Velocidad")==0)
        dron = new DroneVelocidad;
    else{
        if (strcmp(tipo,"Semaforo")==0)
            dron = new DroneSemaforo;
        else
            dron= new DroneEstacionamiento;
    }
}

int Nodo::cmp(Nodo& nuevo) {
    char cad1[10],cad2[10];
    
    dron->getId(cad1);
    nuevo.dron->getId(cad2);
    
    if(strcmp(cad1,cad2)>=0) return 1;
    return 0;    
    
}

int Nodo::valor() {
    //return med->GetCodigo();
}

void Nodo::leedron(ifstream&arch){
    dron->leer(arch);
    
}


//
//void Nodo::impdrone(ofstream&arch) {
//    med->imprimedicamento(arch);
//}
//
//void Nodo::actdrone() {
//    med->actualizamedicamento();
//}
