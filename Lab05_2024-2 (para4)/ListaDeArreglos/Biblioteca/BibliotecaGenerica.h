//
// Created by cueva.r on 30/09/2026.
//

#ifndef LISTADEARREGLOS_BIBLIOTECAGENERICA_H
#define LISTADEARREGLOS_BIBLIOTECAGENERICA_H
#include  <fstream>
using namespace std;
    void construir(void *&lista);
    void crealista(void *&lista,void*(*lee)(ifstream&),
               const char*nom);
    void insertafinal(void*&lista,void*dupla);
    void cargalista(void*&lista,bool(*comprueba)(void*,void*),
        void*(*lee)(ifstream&),const char*nom);
    void agrega(void*&nodo,void *dato);
    void muestralista(void *lista,void(*imprime)(ofstream&,void*),
       const char *nom);
#endif //LISTADEARREGLOS_BIBLIOTECAGENERICA_H
