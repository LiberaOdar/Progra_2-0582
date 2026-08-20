//
// Created by uveag on 18/08/2026.
//

#ifndef SOBRECARGADEALUMMNOS_SOBRECARGA_H
#define SOBRECARGADEALUMMNOS_SOBRECARGA_H
#include <iostream>
#include <iomanip>
#include "Estructuras.h"
using namespace std;
void operator >>(ifstream &arch, Cursos &cur);
void operator >>(ifstream &arch, Alumnos &alu);
bool operator >(Alumnos alu, int codalu);
bool operator >(Cursos cur, char *codcur);
int operator <=(Alumnos *arralu, Alumnos alu);
int operator >=(Cursos *arrcur, Cursos cur);
char *leercadena(ifstream &arch, int max, char delim);

#endif //SOBRECARGADEALUMMNOS_SOBRECARGA_H
