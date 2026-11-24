//
// Created by cueva.r on 30/09/2026.
//

#include <iostream>
#include "ListaconEnteros.h"

using namespace std;

void*leenumeros(ifstream &arch) {
    int num,*pnum;
    arch >> num;
    if (arch.eof())return nullptr;
    pnum = new int;
    *pnum = num;
    return pnum;
}

void *leeregnumeros(ifstream &arch){
    int *clave,*num;
    void **reg;
    reg=new void*[2];
    clave=new int;
    num = new int;
    arch >> *clave >> *num;
    if(arch.eof())return nullptr;
    reg[0]=clave;
    reg[1]=num;
    return reg;
}

bool compruebanumero(void*a,void*b){
    int *ai,*bi;
    ai=(int*)a;
    bi=(int*)b;
    return *ai==*bi;
}

void imprimenumeros(ofstream &arch,void *nodo){
    void **lnodo=(void**)nodo;
    void **lista;
    int *num;

    num=(int*)lnodo[0];
    arch << *num << endl;
    lista=(void**)lnodo[1];

    for(int i=0;lista[i]!=nullptr;i++){
        num = (int*)lista[i];
        arch << *num <<" ";
    }
    arch << endl << endl;
}