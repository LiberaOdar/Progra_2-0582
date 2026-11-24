//
// Created by cueva.r on 18/09/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;
void procesaArreglo(void *,void* (*)(ifstream&),const char*);
void generaLista(void *&lista);
void insertaLista(void *&lista,void *dato);
void creaLista(void *arreglo,void*&lista,
    int (*compara)(const void*,const void*));
void imprimeLista(void *lista,void(*imprime)(ofstream&,void*),
    const char*nom);
#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
