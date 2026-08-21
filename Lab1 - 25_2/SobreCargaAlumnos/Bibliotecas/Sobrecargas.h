//
// Created by cueva.r on 18/08/2026.
//

#ifndef SOBRECARGAALUMNOS_SOBRECARGAS_H
#define SOBRECARGAALUMNOS_SOBRECARGAS_H
#include<fstream>
#include "Estructuras.h"
using namespace std;

    char*leecadena(ifstream& arch,int max,char carlim);
    void operator >>(ifstream&arch ,Alumnos &alu);
    void operator >>(ifstream&arch ,Cursos &cur);
    bool operator>(Alumnos alu,int codalu);
    bool operator>(Cursos cur,char*codcur);
    void operator +=(Cursos &cur,Alumnos &alu);
    void operator ++(Cursos &cur,int b);
    int operator >=(Cursos *arrcur,Cursos cur);
    int operator<=(Alumnos *arralu,Alumnos alu);
    void operator <<(ofstream &arch,Cursos cur);
#endif //SOBRECARGAALUMNOS_SOBRECARGAS_H
