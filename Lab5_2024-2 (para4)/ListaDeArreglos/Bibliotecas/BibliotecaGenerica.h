//
// Created by uveag on 30/09/2026.
//

#ifndef LISTADEARREGLOS_BIBLIOTECAGENERICA_H
#define LISTADEARREGLOS_BIBLIOTECAGENERICA_H
using namespace std;
#include <iostream>
void crealista(void *&lista, void*(*lee)(ifstream &arch), const char *nom);
void construir(void *&lista);
void insertafinal(void *&lista, void *dupla);
#endif //LISTADEARREGLOS_BIBLIOTECAGENERICA_H
