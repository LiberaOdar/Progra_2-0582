//
// Created by cueva.r on 21/08/2026.
//
#include <iostream>
#include <fstream>
#include "Sobrecargas.h"
#include "Funciones.h"
#include "Estructuras.h"

using namespace std;


void leealumnos(Alumnos *arralumno,const char*nom) {
    int i=0;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        arch >> arralumno[i];
        if (arch.eof())break;
        i++;
    }
    //arralumno[i+1].codigo=0;
}

void leecursos(Cursos *arrcurso,const char*nom) {
    int i=0;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        arch >> arrcurso[i];
        if (arch.eof())break;
        i++;
    }
}