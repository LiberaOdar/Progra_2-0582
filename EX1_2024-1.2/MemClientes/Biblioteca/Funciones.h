//
// Created by cueva.r on 26/08/2026.
//

#ifndef MEMCLIENTES_FUNCIONES_H
#define MEMCLIENTES_FUNCIONES_H
#include<fstream>
using namespace std;
    char*leecadena(ifstream& arch,int max,char carlim);
    void cargarClientes(int *&clienteDNI,char **&clienteNombre,
                    const char*nom);
#endif //MEMCLIENTES_FUNCIONES_H
