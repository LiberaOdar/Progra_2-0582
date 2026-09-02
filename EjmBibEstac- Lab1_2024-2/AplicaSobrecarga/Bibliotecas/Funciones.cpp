/*
 * File:   Funciones.cpp
 * Author: cueva.r
 *
 * Created on 1 de abril de 2025, 08:45 AM
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "Funciones.h"
#include "Sobrecarga.h"

using namespace std;

void leeplatos(Plato *arr,const char *nombre){
    int i=0;
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nombre << endl;
        exit(1);
    }
    while(1){
        arch >> arr[i];
        if(arch.eof())break;
        i++;
    }
    strcpy(arr[i].codigo,"FIN");

}

void leerepartidor(Repartidor *arr,const char *nombre){
    int i=0;
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nombre << endl;
        exit(1);
    }
    while(1){
        arch >> arr[i];
        if(arch.eof())break;
        i++;
    }
    strcpy(arr[i].codigo,"FIN");

}

void leepedido(Pedido *arr,const char *nombre){
    int i=0;
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nombre << endl;
        exit(1);
    }

    while(1){
        arch >> arr[i];
        if(arch.eof())break;

        i++;
    }
    arr[i].dniDelCliente=0;

}

void cargayimprime(Pedido *arrped,Plato *arrpla,Repartidor *arrrepa,
        const char*nom){
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nom << endl;
        exit(1);
    }

    for(int i=0;arrped[i].dniDelCliente!=0;i++){
        arrped[i]<=arrpla;
        arrrepa<=arrped[i];

    }
    for(int i=0;strcmp(arrrepa[i].codigo,"FIN")!=0;i++){
        !arrrepa[i];
        arch << arrrepa[i];

    }

}