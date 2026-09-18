//
// Created by cueva.r on 18/09/2026.
//
#include <iostream>
#include "BibliotecaGenerica.h"

using namespace std;

void procesaArreglo(void *arreglo,void* (*lee)(ifstream&),
    const char*nom) {
    void **larreglo=(void**)arreglo;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"Error al abrir "<<nom<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        larreglo[i]=lee(arch);
        if (arch.eof()) break;
        i++;
    }
}

void creaLista(void *arreglo,void*&lista,
    int (*compara)(const void*,const void*) ) {
    int n=0;
    void **larreglo=(void**)arreglo;
    for (int i=0;larreglo[i];i++)n++;
    qsort(larreglo,n,sizeof(void*),
        compara);


}