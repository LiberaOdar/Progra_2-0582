//
// Created by cueva.r on 2/09/2026.
//

#ifndef MEMINCCLIENTES_FUNCIONES_H
#define MEMINCCLIENTES_FUNCIONES_H
#include <fstream>
using namespace std;
    char*leecadena(ifstream& arch,int max,char carlim);
    void aumentarespacio(int *&arrcodigo,char**&arrnombre,
        int &capacidad, int &numdatos);
void cargaclientes(int *&arrcodigo,char**&arrnombre,
    const char*nom);
#endif //MEMINCCLIENTES_FUNCIONES_H
