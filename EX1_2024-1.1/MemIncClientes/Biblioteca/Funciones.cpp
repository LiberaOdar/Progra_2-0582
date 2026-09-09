//
// Created by cueva.r on 2/09/2026.
//

#include "Funciones.h"
#include <iostream>
#include <fstream>
#include <cstring>
#define INC 5

using namespace std;

//54393647,Reyes Tang Edward
void cargaclientes(int *&arrcodigo,char**&arrnombre,
    const char*nom) {
    ifstream arch(nom, ifstream::in);
    if (not arch) {
        cout << "Error al abrir el archivo de entrada " << nom <<endl;
        exit(1);
    }
    int numdatos=0,capa=0,dni;
    char *nombre;
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        nombre=leecadena(arch,100,'\n');
        if (capa==numdatos)
            aumentarespacio(arrcodigo,arrnombre,capa,numdatos);
        arrcodigo[numdatos-1]=dni;
        arrnombre[numdatos-1]=nombre;
        numdatos++;
    }
}

void aumentarespacio(int *&arrcodigo,char**&arrnombre,
    int &capacidad, int &numdatos) {
    int *auxcodigo;
    char **auxnombre;
    capacidad+=INC;
    if (numdatos==0) {
        arrcodigo=new int[capacidad]{};
        arrnombre=new char*[capacidad]{};
        numdatos++;
    }
    else {
        auxcodigo=new int[capacidad]{};
        auxnombre=new char*[capacidad]{};
        for (int i=0;i<numdatos;i++) {
            auxcodigo[i]=arrcodigo[i];
            auxnombre[i]=arrnombre[i];
        }
        delete arrcodigo;
        delete arrnombre;
        arrcodigo=auxcodigo;
        arrnombre=auxnombre;
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
