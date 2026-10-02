//
// Created by cueva.r on 30/09/2026.
//

#ifndef LISTADEARREGLOS_LISTACONENTEROS_H
#define LISTADEARREGLOS_LISTACONENTEROS_H
#include <fstream>
using namespace std;
    void*leenumeros(ifstream &arch);
    void *leeregnumeros(ifstream &arch);
    bool compruebanumero(void*,void*);
    void imprimenumeros(ofstream &arch,void *);

#endif //LISTADEARREGLOS_LISTACONENTEROS_H
