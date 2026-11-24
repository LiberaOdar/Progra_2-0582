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

void imprimeLista(void *lista,void(*imprime)(ofstream&,void*),
    const char*nom) {
    void **llista=(void**)lista;
    void **prec=(void**)llista[0];
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"Error al abrir "<<nom<<endl;
        exit(1);
    }
    while (prec) {
        imprime(arch,prec[0]);
        prec=(void**)prec[1];
    }

}

void creaLista(void *arreglo,void*&lista,
    int (*compara)(const void*,const void*) ) {
    int n=0;
    void **larreglo=(void**)arreglo;
    for (int i=0;larreglo[i];i++)n++;
    qsort(larreglo,n,sizeof(void*),
        compara);
    generaLista(lista);
    for (int i=0;larreglo[i];i++)
        insertaLista(lista,larreglo[i]);
}

void insertaLista(void *&lista,void *dato) {
    void**llista=(void**)lista;
    void **prec=(void**)llista[0];
    void **nuevo=new void*[2]{};
    nuevo[0]=dato;
    if (prec==nullptr)
        llista[0]=nuevo;
    else {
        nuevo[1]=prec;
        llista[0]=nuevo;
    }
    int *num=(int*)llista[1];
    *num++;
}

void generaLista(void *&lista) {
    int *num;
    void **dupla=new void*[2];
    num=new int;
    *num=0;
    dupla[0]=nullptr;
    dupla[1]=num;
    lista=dupla;
}