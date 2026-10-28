//
// Created by cueva.r on 6/10/2026.
//

#include "Restaurante.h"
#include <cstring>
#include <iostream>
#define INC 5

using namespace std;

Restaurante::Restaurante() {
    clientes=nullptr;
    platos=nullptr;
    cantDeClientes=0;
    cantDePlatos=0;
    capaDePlatos=0;
}

Restaurante::~Restaurante() {
    if (clientes!=nullptr) delete[] clientes;
    if (platos!=nullptr) delete[] platos;
}


void Restaurante::cargaclientes(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Cliente aux;
        aux.lee_cliente(arch);
        if (arch.eof()) break;
        clientes[cantDeClientes].asigna(aux);
        cantDeClientes++;
    }
}

void Restaurante::borracliente() {
    clientes[cantDeClientes-1].libera();
    cantDeClientes--;
}

void Restaurante::cargaplatos(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        platos[cantDePlatos].leeplato(arch);
        if (arch.eof()) break;
        cantDePlatos++;
    }

}

void Restaurante::operator<(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    Cliente buffer[200];
    while (true) {
        arch >> buffer[cantDeClientes];
        //probando copia
        //buffer[cantDeClientes].llamando(buffer[cantDeClientes]);
        if (arch.eof()) break;
        cantDeClientes++;
    }
    clientes=new Cliente[cantDeClientes+1];
    for (int i=0;i<cantDeClientes;i++)
        clientes[i]=buffer[i];

}

void Restaurante::operator<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Plato aux;
        arch >> aux;
        if (arch.eof())break;
        if (capaDePlatos==cantDePlatos)
            aumentarespacio();
        platos[cantDePlatos-1]=aux;
        cantDePlatos++;
    }
}

void Restaurante::aumentarespacio() {
    Plato *auxplato;
    capaDePlatos+=INC;
    if (cantDePlatos==0) {
        platos= new Plato[capaDePlatos];
        cantDePlatos++;
    }
    else {
        auxplato= new Plato[capaDePlatos];
        for (int i=0;i<cantDePlatos;i++)
            auxplato[i]=platos[i];
        delete []platos;
        platos=auxplato;
    }
}

void Restaurante::imprimirclientes(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    for (int i=0;i<cantDeClientes;i++)
        clientes[i].imprime_cliente(arch);

}

void Restaurante::procesapedidos(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int numped,dni;
    char c;
// 961419,77324146,SA53764,9,AD90766,4,EN90758,1
    while (true) {
        arch >> numped;
        if (arch.eof()) break;
        arch >> c>>dni>>c;
        int posclie=buscacliente(dni);
        if (posclie!=-1)
                procesaplatos(posclie,arch);
        else
            while (arch.get()!='\n');
    }
}

int Restaurante::buscacliente(int dni) {
    for (int i=0;i<cantDeClientes;i++)
        if (clientes[i].get_dni()==dni)
            return i;
    return -1;
}
// SA53764,9,AD90766,4,EN90758,1
void Restaurante::procesaplatos(int pos, ifstream &arch) {
    char codpla[10];
    int cant;
    while (true) {
        arch.getline(codpla,10,',');
        arch >> cant;
        int posplato=buscaplato(codpla);
        if (posplato!=-1) {
            if (platos[posplato].get_preparados()>=platos[posplato].get_atendidos()+cant) {
                actualizatodo(pos,posplato,cant);
            }
        }
        if (arch.get()=='\n')break;
    }
}

int Restaurante::buscaplato(char* codplato) {
    for (int i=0;i<cantDePlatos;i++) {
        char cad[10];
        platos[i].get_codigo(cad);
        if (strcmp(codplato,cad)==0)
            return i;
    }
    return -1;
}

void Restaurante::actualizatodo(int poscli, int pospla, int cant) {
    // actualizo clientes
    double precio=platos[pospla].get_precio();
    double desccli=clientes[poscli].get_descuento();
    double total= precio*cant*(1-desccli/100);
    clientes[poscli].set_totalpagado(clientes[poscli].get_totalpagado()+total);
    // actualizo platos
    platos[pospla].set_atendidos(platos[pospla].get_atendidos()+cant);
}
