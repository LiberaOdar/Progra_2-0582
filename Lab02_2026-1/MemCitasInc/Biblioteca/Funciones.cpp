//
// Created by cueva.r on 9/09/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Funciones.h"
#define INC 5

using namespace std;

void cargarInformacion(const char *nom,
    int *&fechas,char ****&datosDeTexto) {
    fechas=nullptr;
    datosDeTexto=nullptr;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    char c;
    int numdatos=0,capacidad=0,dd,mm,aa,fecha;
    int arrnumdatos[1000]{};
    int arrcapacidad[1000]{};
    //6/04/2024,864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
    while (true) {
        arch>>dd;
        if (arch.eof())break;
        arch>>c>>mm>>c>>aa>>c;
        fecha=aa*10000+mm*100+dd;
        int pos=buscafecha(fecha,fechas);
        if (pos==-1)
            insertafechas(fecha,fechas,datosDeTexto,
                capacidad,numdatos,pos);
        agregadatos(arch,datosDeTexto[pos],arrcapacidad[pos],
            arrnumdatos[pos]);
    }
}
// 864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia

void agregadatos(ifstream &arch,char ***&datos,int &capa,
    int &num) {
    char cadena[100];
    char **tripleta;
    tripleta=new char*[3];
    tripleta[0]=leecadena(arch,20,',');
    tripleta[1]=leecadena(arch,100,',');
    for (int i=0;i<5;i++)
        arch.getline(cadena,20,',');
    tripleta[2]=leecadena(arch,50,'\n');
    if (num==capa)
        aumentarhorizontal(datos,capa,num);
    datos[num-1]=tripleta;
    num++;
}


void insertafechas(int fecha,int *&arrfechas,
    char ****&datosDeTexto,int &capacidad,int &numdatos,int &pos) {
    if (numdatos==capacidad)
        aumentarespacio(arrfechas,datosDeTexto,capacidad,numdatos);
    arrfechas[numdatos-1]=fecha;
    pos=numdatos-1;
    numdatos++;
}

int buscafecha(int fecha,int *arrfechas) {
    if (arrfechas==nullptr) return -1;
    for (int i=0;arrfechas[i];i++)
        if (fecha==arrfechas[i]) return i;
    return -1;
}

void aumentarhorizontal(char ***&datosDeTexto,int &capa,int &num) {
    char ***auxdatos;
    capa+=INC;
    if (num==0) {
        datosDeTexto=new char**[capa]{};
        num++;
    }
    else {
        auxdatos=new char**[capa]{};
        for (int i=0;i<num;i++)
            auxdatos[i]=datosDeTexto[i];
        delete datosDeTexto;
        datosDeTexto=auxdatos;
    }
}

void aumentarespacio(int *&fechas, char ****&datosDeTexto,
    int &capa,int &num) {
    int *auxfechas;
    char ****auxdatos;
    capa+=INC;
    if (num==0) {
        fechas=new int[capa]{};
        datosDeTexto=new char***[capa]{};
        num++;
    }
    else {
        auxfechas=new int[capa]{};
        auxdatos=new char***[capa]{};
        for (int i=0;i<num;i++) {
            auxfechas[i]=fechas[i];
            auxdatos[i]=datosDeTexto[i];
        }
        delete fechas;
        delete datosDeTexto;
        fechas=auxfechas;
        datosDeTexto=auxdatos;
    }
}

void imprimefechas(int *fechas,char ****datos,
    const char *nombre) {
    ofstream arch(nombre,ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nombre<<endl;
        exit(1);
    }
    for (int i=0;fechas[i];i++) {
        arch<<endl<<left <<"La fecha de cita es: "<< fechas[i] << endl;
        char ***auxdatos;
        auxdatos=datos[i];
        for (int j=0;auxdatos[j];j++) {
            char **auxtripleta;
            auxtripleta=auxdatos[j];
            arch<<setw(10)<< auxtripleta[0];
            arch<<setw(20)<< auxtripleta[1];
            arch<<setw(10)<< auxtripleta[2]<<endl;
        }
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