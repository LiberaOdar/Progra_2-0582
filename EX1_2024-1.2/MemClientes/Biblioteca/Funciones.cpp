//
// Created by cueva.r on 26/08/2026.
//

#include "Funciones.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
// 54393647,Reyes Tang Edward
void cargarClientes(int *&clienteDNI,char **&clienteNombre,
                    const char*nom) {
    int buffdni[100];
    char *buffnom[100];
    ifstream arch(nom,ios::in);
    if(!arch) {
        cout <<"No se puede abrir "<<nom<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch >> buffdni[i];
        if (arch.eof()) break;
        arch.get();
        buffnom[i]=leecadena(arch,100,'\n');
        i++;
    }
    clienteDNI=new int[i+1]{};
    clienteNombre=new char*[i+1]{};

    for (int j=0;j<i;j++) {
        clienteDNI[j]=buffdni[j];
        clienteNombre[j]=buffnom[j];
    }

}




char*leecadena(ifstream& arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}