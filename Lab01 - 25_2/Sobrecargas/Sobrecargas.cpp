//
// Created by cueva.r on 18/08/2026.
//

#include "Sobrecargas.h"

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"

using namespace std;
//modificando para tener lectura seguida
//INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
void operator >>(ifstream&arch ,Cursos &cur) {
    char c;
    int num;
    cur.codigo=leecadena(arch,10,',');
    if (cur.codigo==nullptr)return;
    cur.nombre=leecadena(arch,100,',');
    arch >> cur.creditos>>c>>num>>c;
    cur.docente=leecadena(arch,100,'\n');
    cur.numpresencial=0;
    cur.numsemipresencial=0;
    cur.numvirtual=0;
}
// 202111260,GORDILLO/CASTRO/RONAL,P
void operator >>(ifstream&arch ,Alumnos &alu) {
    char c;
    arch>>alu.codigo;
    if (arch.eof())return;
    arch>>c;
    alu.nombre=leecadena(arch,50,',');
    arch>>alu.tipo;
}

bool operator>(Alumnos alu,int codalu) {
    if (alu.codigo==codalu)return true;
    return false;
}

bool operator>(Cursos cur,char*codcur) {
    if (strcmp(cur.codigo,codcur)==0)return true;
    return false;
}

void operator +=(Cursos &cur,Alumnos &alu) {
    if (alu.tipo=='P') {
        cur.presencial[cur.numpresencial]=alu;
        cur.numpresencial++;
    }
    if (alu.tipo=='S') {
        cur.semipresencial[cur.numsemipresencial]=alu;
        cur.numsemipresencial++;
    }
    if (alu.tipo=='V') {
        cur.vvirtual[cur.numvirtual]=alu;
        cur.numvirtual++;
    }
}

int operator<=(Alumnos *arralu,Alumnos alu) {
    for (int i=0;arralu[i].codigo!=0;i++)
        if (arralu[i]>alu.codigo)return i;
    return -1;
}

int operator >=(Cursos *arrcur,Cursos cur) {
    for (int i=0;arrcur[i].codigo!=nullptr;i++)
        if (arrcur[i]>cur.codigo)return i;
    return -1;
}

void operator ++(Cursos &cur,int b) {
    int total=cur.numpresencial+cur.numsemipresencial+cur.numvirtual;
    double porc=1.0*cur.numpresencial/total;
    cur.tipofinal=new char[30];
    if (porc>=0.5)
        strcpy (cur.tipofinal,"La clase se dictara en aula");
    else
        strcpy (cur.tipofinal,"La clase se dictara virtual");
}

void operator <<(ofstream &arch,Cursos cur) {
    arch<<setw(10)<<cur.codigo<<" "<<setw(30)<<cur.nombre<<endl;
    arch<<cur.docente<<endl;
    arch<<"Numero Presenciales:  "<<cur.numpresencial<<endl;
    arch<<"Numero Semipresencial:"<<cur.numsemipresencial<<endl;
    arch<<"Numero Virtual:  "<<cur.numvirtual<<endl;
    arch<<cur.tipofinal<<endl<<endl;

}




char*leecadena(ifstream& arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

