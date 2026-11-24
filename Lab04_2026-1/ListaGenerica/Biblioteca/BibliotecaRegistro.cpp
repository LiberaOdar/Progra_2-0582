//
// Created by cueva.r on 22/09/2026.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include "BibliotecaRegistro.h"

using namespace std;

// 101,7/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
void* leeregistro(ifstream &arch) {
    int codigo,*pfecha,dd,mm,aa,*pcodigo,*phora,ho,mi;
    char c,cadena[100],*pnombre,*praza,*pcolor;
    arch >> codigo;
    if (arch.eof())return nullptr;
    pcodigo=new int;
    *pcodigo=codigo;
    arch>>c>>dd>>c>>mm>>c>>aa>>c;
    pfecha=new int;
    *pfecha=aa*10000+mm*100+dd;
    arch.getline(cadena,100,',');
    arch>>ho>>c>>mi>>c;
    phora=new int;
    *phora=ho*60+mi;
    arch.getline(cadena,100,',');
    pnombre=leecadena(arch,100,',');
    praza=leecadena(arch,100,',');
    pcolor=leecadena(arch,100,',');
    arch.getline(cadena,100,'\n');
    void**reg;
    reg=new void*[6];
    reg[0]=pfecha;
    reg[1]=phora;
    reg[2]=pcodigo;
    reg[3]=pnombre;
    reg[4]=praza;
    reg[5]=pcolor;

    return reg;
}

char*leecadena(ifstream& arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

int comparareg(const void *a,const void *b) {
    void **pa,**pb,**rega,**regb;
    int *fec1,*fec2,*hor1,*hor2;

    pa =(void **)a;
    pb =(void **)b;
    rega =(void**)pa[0]; // pa[0] es igual *pa
    regb =(void**)pb[0];
    fec1 = (int*)rega[0];
    fec2 = (int*)regb[0];
    hor1 = (int*)rega[1];
    hor2 = (int*)regb[1];
    if (*fec2-*fec1!=0) return *fec2-*fec1;
    return *hor2-*hor1;
}

void imprimeregistro(ofstream &arch,void*dato) {
    void **reg=(void**)dato;
    int *pcodigo,*pfecha,*phora;
    char *nombre,*praza,*pcolor;

    pfecha=(int*)reg[0];
    phora=(int*)reg[1];
    pcodigo=(int*)reg[2];
    nombre=(char*)reg[3];
    praza=(char*)reg[4];
    pcolor=(char*)reg[5];

    arch <<setw(4)<< *pfecha<<setw(4)<< *phora<<setw(10)<<*pcodigo;
    arch << setw(40)<<nombre <<setw(40)<<praza <<setw(40)<<pcolor <<endl;

}