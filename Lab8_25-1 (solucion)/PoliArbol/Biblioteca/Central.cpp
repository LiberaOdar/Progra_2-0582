
/* 
 * File:   Central.cpp
 * Author: cueva
 * 
 * Created on 18 de junio de 2025, 06:14 PM
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "Central.h"

using namespace std;

Central::Central() {
}

Central::Central(const Central& orig) {
}

Central::~Central() {
}

void Central::carga(){
    ifstream arch("drones.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de drones";
        exit(1);
    }
    while(1){
        ADrones.inserta(arch);
        if(arch.eof())break;
    }
    
}

void Central::muestra(){
    ofstream arch("reporte.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }    
    ADrones.imprimerep(arch);

}

void Central::actualiza(){
    ADrones.actualiza();
}