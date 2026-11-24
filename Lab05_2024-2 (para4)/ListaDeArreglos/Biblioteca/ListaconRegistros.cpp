/* 
 * File:   ColaconRegistros.cpp
 * Author: cueva
 * 
 * Created on 8 de octubre de 2024, 07:38 AM
 */
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "ListaconRegistros.h"

using namespace std;

/*
JNV387,Justino Norabuena Virginia Karina,Motocicleta
PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
 */

void *leeregistros(ifstream &arch){
    char *cod,*nom,*veh;
    
    cod=leerCadena(arch,10,',');
    if(arch.eof()) return nullptr;
    nom=leerCadena(arch,100,',');
    veh=leerCadena(arch,20,'\n');
    void **aux;
    aux=new void*[3];
    aux[0]=cod;
    aux[1]=nom;
    aux[2]=veh;
    
    return aux;    
    
}

void imprimeregistros(ofstream &arch,void *nodo){
    char *cod,*nom,*veh;
    void **lnodo=(void**)nodo;
    void **lista;
    
    void **reg=(void**)lnodo[0];
    cod=(char*)reg[0];
    nom=(char*)reg[1];
    veh=(char*)reg[2];
    arch <<left<<setw(10)<< cod<<setw(50)<<nom<<setw(20)<<veh<<endl;
    
    lista=(void**)lnodo[1];
    int *dni,*cant;
    char *plato,*codigo;
    
    for(int i=0;lista[i]!=nullptr;i++){
        void**reg=(void**)lista[i];
        dni=(int*)reg[0];
        cant=(int*)reg[1];
        plato=(char*)reg[2];
        codigo=(char*)reg[3];
        arch << setw(15)<< *dni<<setw(5)<<*cant<<setw(10)<<plato;
        arch << setw(10)<< codigo <<endl;
    }
    arch << endl << endl;   
}

/* 
12484697, 2, AD - 546, LAF361
12484697, 1, PO - 751, LAF361
*/
void *leeordenes(ifstream &arch){
    int *dni,*cant;
    char *plato,*codigo;
    
    dni=new int;
    arch >> *dni;
    if(arch.eof())return nullptr;
    arch.get();
    cant=new int;
    arch >> *cant;
    arch.get();
    plato=leerCadena(arch,10,',');
    codigo=leerCadena(arch,10,'\n');
    void **aux =new void*[2];
    void **reg=new void*[4];
    reg[0]=dni;
    reg[1]=cant;
    reg[2]=plato;
    reg[3]=codigo;
    
    aux[0]=codigo;
    aux[1]=reg;
    return aux;
}

bool compruebaregistro(void*a,void*b){
    char *rep,*ped;
    void**orden=(void**)a;
    void**moto=(void**)b;
    ped=(char*)orden[0];
    rep=(char*)b;
    if(strcmp(ped,rep)==0)
        return true;
    return false;
    
}

char *leerCadena(ifstream &arch, int n, char c){
    char buffer[n], *cadena;
    arch.getline(buffer, n, c);
    if(arch.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}