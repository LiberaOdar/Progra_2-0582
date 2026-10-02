//
// Created by uveag on 30/09/2026.
//

#include "BibliotecaGenerica.h"

#include <iostream>
#include <fstream>
using namespace std;
void crealista(void *&lista, void*(*lee)(ifstream&), const char *nom) {
    ifstream arch(nom, ios::in);
    if (not arch) {
        cout<<"Error al abrir el archivo"<<endl;
    }
    construir(lista);
    void *dato, **dupla;
    while (true) {
        dato=lee(arch);
        if (arch.eof()) break;
        dupla=new void *[2]{};
        dupla[0]=dato;
        dupla[1]=new void *[20]{};
        insertafinal(lista, dupla);
    }

}

void construir(void *&lista) {
    int *num = new int;
    void **llista=new void *[3]{};
    *num=0;
    llista[2]=num;
    lista=llista;
}

void insertafinal(void *&lista, void *dupla) {
    void **llista=(void **)lista;
    void **nuevo=new void *[2]{};
    nuevo[0]=dupla;
    if (llista[1]==nullptr) {
        llista[0]=nuevo;
        llista[1]=nuevo;
    } else {
        void **prec=(void **)llista[1]; //entra al siguiente del nodo
        prec[1]=nuevo; //esto es para no perder el lazo entre datos
        llista[1]=nuevo;
    }
    int *num=(int*)llista[2];
    (*num)++;
}

void cargalista(void *lista, bool(*comprueba)(void*, void*), void *(*lee)(ifstream&), const char *nom) {
    ifstream arch(nom, ios::in);
    if (not arch) {
        cout<<"Error al abrir el archivo"<<endl;
    }
    void *dato, **llista=(void **)lista;
    while (true) {
        dato=lee(arch);
        if (arch.eof()) break;
        void **prec=(void **)llista[0];
        while (prec) {
            void **dupla=(void **)prec[0];
            void **ldato=(void **)dato;
            if (comprueba(dupla[0],ldato[0])) {
                //agrega
                break;
            }
            prec=(void **)prec[1]; //actualiza a recorrer si no se agrega 
        }
    }
}