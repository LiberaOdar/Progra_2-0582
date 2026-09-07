//
// Created by cueva.r on 26/08/2026.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "MetodoExactoMemoria.h"

using namespace std;

//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23

void lecturaDeLibros(const char * nom,char ***&libros,
    int **&stock) {

    int *buffstock[300]{};
    char **bufflibro[300]{};
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        char *cad;
        bufflibro[i]=leelibro(arch);
        if (arch.eof()) break;
        buffstock[i]=leestock(arch);
        i++;
    }
    stock=new int*[i+1]{};
    libros=new char**[i+1]{};
    for (int j=0;j<i;j++) {
        stock[j]=buffstock[j];
        libros[j]=bufflibro[j];
    }
}
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
char **leelibro(ifstream& arch) {
    char *codigo,**reglibro;
    codigo=leecadena(arch,10,',');
    if (arch.eof()) return nullptr;
    reglibro=new char*[3];
    reglibro[0]=codigo;
    reglibro[1]=leecadena(arch,100,',');
    reglibro[2]=leecadena(arch,100,',');
    return reglibro;

}

void atencionDePedidos(const char *nom,char ***libros,int **stock,
    int **&pedidosClientes) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "Error no se puede abrir "<<nom<<endl;
        exit(1);
    }
    // 000118,76693511   DEK2757     FMX8255  CJN4376
    int codped,dni,*buffclie[200]{};
    char c,cad[100];
    while (true) {
        arch >> codped;
        if (arch.eof()) break;
        arch >> c >> dni;
        asignarpedidos(dni,buffclie,codped);
        arch.getline(cad,100);
    }
    int cant=0;
    for (int j=0;buffclie[j];j++)cant++;
    pedidosClientes=new int*[cant+1]{};
    for (int i=0;i<cant;i++)
        pedidosClientes[i]=buffclie[i];

}

void asignarpedidos(int dni,int **pedidosClientes,
    int codpedido) {
    int *clienteaux;
    int posi=buscacliente(dni,pedidosClientes);
    if (posi==-1) {
        clienteaux = new int[100]{};
        clienteaux[0]=dni;
        int cant=0;
        for (int j=0;pedidosClientes[j];j++)cant++;
        pedidosClientes[cant]=clienteaux;
        posi=cant;
    }
    asignarpedidocliente(codpedido,pedidosClientes[posi]);
}
void asignarpedidocliente(int codpedido,int *clientes) {
    int n=clientes[1];
    clientes[n+2]=codpedido;
    clientes[1]++;
}

int buscacliente(int dni,int **pedidosClientes) {
    int *dniaux;
    for (int i=0;pedidosClientes[i];i++) {
        dniaux=pedidosClientes[i];
        if (dni==*dniaux)return i;
    }
    return -1;
}

int* leestock(ifstream& arch) {
    int *dupla;
    char c;
    double precio;
    dupla=new int[2]{};
    arch>>dupla[0]>>c>>precio;
    arch.get();
    return dupla;
}



char*leecadena(ifstream& arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

