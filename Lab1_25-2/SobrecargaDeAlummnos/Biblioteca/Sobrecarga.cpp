//
// Created by uveag on 18/08/2026.
//

#include "Sobrecarga.h"

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"


using namespace std;

//modificando el enunciado para tener lectura seguida
//INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
//esta es una función de sobrecarga, solo va a leer una línea, para que lea más debería ser llamado dentro de un while
//pq le puso ifstream&?
void operator >>(ifstream &arch, Cursos &cur) {
    char c;
    int num;
    //primero, la lectura
    cur.codigo=leercadena(arch, 10, ',');
    cur.nombre=leercadena(arch, 100, ',');
    if (cur.codigo==nullptr) return;
    arch>>cur.creditos>>c>>num>>c;
    cur.docente=leercadena(arch, 100, '\n');
    cur.numpresencial=0;
    cur.numpresencial=0;
    cur.numsemipresencial=0;
    cur.numvirtual=0;
   // return arch;
}
//202111260,GORDILLO/CASTRO/RONAL,P
void operator >>(ifstream &arch, Alumnos &alu) {
    char c;
    arch>>alu.codigo;
    if (arch.eof()) return; //para regresar y no llenar de basura el arreglo;
    arch>>c;
    alu.nombre=leercadena(arch, 50, ',');
    arch>>alu.tipo;
}

bool operator >(Alumnos alu, int codalu) {
    if (alu.codigo==codalu) return true;
    return false;
}

bool operator >(Cursos cur, char *codcur) {
    if (strcmp(cur.codigo, codcur)==0) return true;
    return false;
}

void operator +=(Cursos &cur, Alumnos alu) {
    if (alu.tipo=='P') {
        cur.presencial[cur.numpresencial++]=alu; //manda el arreglo completo
        //es lo mismo que
        //  cur.presencial[cur.numpresencial]=alu;
        // cur.numpresencial++;
    }
    if (alu.tipo=='S') cur.semipresencial[cur.numsemipresencial++]=alu; //manda el arreglo completo
    if (alu.tipo=='V') cur.vvirtual[cur.numvirtual++]=alu; //manda el arreglo completo
}

int operator <=(Alumnos *arralu, Alumnos alu) { //*arr arreglo de estructuras
    for (int i=0; arralu[i].codigo!=0; i++) //terminator
        if (arralu[i]>alu.codigo) return i; //encontrado
    return -1;
}

int operator >=(Cursos *arrcur, Cursos cur) { //*arr arreglo de estructuras
    for (int i=0; arrcur[i].codigo!=nullptr; i++) //terminator
        if (arrcur[i]>cur.codigo) return i; //encontrado
    return -1;
}

void operator ++(Cursos &cur, int b) {
    int total=cur.numpresencial+cur.numvirtual+cur.numsemipresencial;
    double porcentaje=1.0*cur.numpresencial/total;
    cur.tipofinal=new char[30];
    if (porcentaje>=0.5) strcpy(cur.tipofinal, "La clase se dictara en aula.");
    else strcpy(cur.tipofinal, "La clase se dictara 100% virtual.");
}





char *leercadena(ifstream &arch, int max, char delim) {
    char buff[max], *cad; //arreglo de cadenas, recuerda, repasa
    arch.getline(buff, max, delim);
    if (arch.eof()) return nullptr; //condicional por si está en el fin de archivo
    //OJO, recuerda que en la lectura es donde más se cae el programa
    cad= new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}