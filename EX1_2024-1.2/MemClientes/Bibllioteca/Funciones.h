//
// Created by uveag on 28/08/2026.
//

#ifndef MEMCLIENTES_FUNCIONES_H
#define MEMCLIENTES_FUNCIONES_H
#include <iostream>
using namespace std;
char *leercadena(ifstream &arch, int max, char delim);
void cargarClientes(int *&clienteDNI, char **&clienteNombre, const char *nom);
#endif //MEMCLIENTES_FUNCIONES_H
