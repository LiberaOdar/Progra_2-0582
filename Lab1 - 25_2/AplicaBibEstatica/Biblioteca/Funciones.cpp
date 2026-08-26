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
//INF263,202318320
void leematricula(Cursos *arrcurso,Alumnos*arralumno,
    const char*nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Cursos curaux;
        Alumnos aluaux;
        curaux.codigo=leecadena(arch,10,',');
        if (arch.eof())break;
        arch>>aluaux.codigo;
        arch.get();
        int indcur=arrcurso>=curaux;
        int indalu=arralumno<=aluaux;
        arrcurso[indcur]+=arralumno[indalu];
    }
}

void imprimecursos(Cursos *arrcurso,const char*nom ) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }

    for (int i=0;arrcurso[i].codigo!=nullptr;i++) {
        arrcurso[i]++;
        arch <<arrcurso[i];
    }
}