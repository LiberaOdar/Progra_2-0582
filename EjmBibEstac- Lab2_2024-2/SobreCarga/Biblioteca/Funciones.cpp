
/*
 * File:   Funciones.cpp
 * Author: cueva.r
 *
 * Created on 1 de abril de 2025, 08:45 AM
 */
#include <iostream>
#include <cstring>
#include "Funciones.h"
#include "AperturaDeArchivos.h"
#include "Sobrecarga.h"


void leeplatos(Plato *arr,const char *nombre){
    ifstream arch;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);

    while(1){
        arch >> arr[i];
        if(arch.eof())break;
        i++;
    }
    strcpy(arr[i].codigo,"FIN");

}

void leerepartidor(Repartidor *arr,const char *nombre){
    ifstream arch;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);

    while(1){
        arch >> arr[i];
        if(arch.eof())break;
        i++;
    }
    strcpy(arr[i].codigo,"FIN");

}

void leepedido(Pedido *arr,const char *nombre){
    ifstream arch;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombre);

    while(1){
        arch >> arr[i];
        if(arch.eof())break;

        i++;
    }
    arr[i].dniDelCliente=0;

}

void cargayimprime(Pedido *arrped,Plato *arrpla,Repartidor *arrrepa,
        const char*nom){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nom);

    for(int i=0;arrped[i].dniDelCliente!=0;i++){
        arrped[i]<=arrpla;
        arrrepa<=arrped[i];

    }
    for(int i=0;strcmp(arrrepa[i].codigo,"FIN")!=0;i++){
        !arrrepa[i];
        arch << arrrepa[i];

    }

}
