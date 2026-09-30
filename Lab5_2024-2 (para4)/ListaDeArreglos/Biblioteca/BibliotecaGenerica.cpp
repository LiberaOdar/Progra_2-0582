//
// Created by cueva.r on 30/09/2026.
//

#include "BibliotecaGenerica.h"
#include <iostream>

using namespace std;

void crealista(void *&lista,void*(*lee)(ifstream&),
               const char*nom) {
    void*dato,**dupla;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir "<<nom<<endl;
        exit(1);
    }
    construir(lista);
    while (true) {
        dato = lee(arch);
        if (arch.eof())break;
        dupla=new void*[2];
        dupla[0]=dato;
        dupla[1]=new void*[20]{};
        insertafinal(lista,dupla);
    }
}

void insertafinal(void*&lista,void*dupla) {
    void**nuevo;
    void**llista=(void**)lista;

    nuevo = new void*[2]{};
    nuevo[0] = dupla;
    if (llista[1]==nullptr) {
        llista[0]=nuevo;
        llista[1]=nuevo;
    }
    else {
        void**prec=(void**)llista[1];
        prec[1]=nuevo;
        llista[1]=nuevo;
    }
    int *num=(int*)llista[2];
    (*num)++;
}

void construir(void *&lista) {
    int *num;
    void **llista=new void*[3]{};
    num=new int;
    *num=0;
    llista[2]=num;
    lista=llista;
}

void cargalista(void*&lista,bool(*comprueba)(void*,void*),
    void*(*lee)(ifstream&),const char*nom) {
    void *dato;
    void**llista=(void**)lista;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir "<<nom<<endl;
        exit(1);
    }
    while (true) {
        dato=lee(arch);
        if (arch.eof())break;
        void **prec=(void**)llista[0];
        while (prec) {
            void **dupla=(void**)prec[0];
            void **ldato=(void**)dato;
            if (comprueba(dupla[0],ldato[0])) {
                //falta agrega
                break;
            }
            prec=(void**)prec[1];
        }

    }



}