//
// Created by uveag on 28/08/2026.
//

#include "Funciones.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

//son dos parametros porque vamos a leer dos arreglos al mismo tiempo
//colocas & para que se pueda modificar
void cargarClientes(int *&clienteDNI, char **&clienteNombre, const char *nom) {
    ifstream arch(nom, ios::in);
    if (!arch) {
        cout << "Error al abrir el archivo"<< nom << endl;
        exit(1);
    }
    //buffer: lugar donde colocas algo temporal
    //54393647,Reyes Tang Edward
    int buffdni[100]; //ya es estático si colocas otro ** es como una matriz donde
    //abres otra serie de cajitas para el primero
    //cuando son arreglos paralelos, tienes q colocar la misma cantidad de datos
    //que manejas desde el primer arreglo base
    char *buffnom[100];
    int i=0;
    while (true) {
        arch>>buffdni[i];
        if (arch.eof()) break;
        arch.get();//la coma
        buffnom[i]=leercadena(arch, 100,'\n');
        i++;
    }
    //esto es para el terminator, la última posición
    clienteDNI=new int[i+1]{}; //en base a este es que se hacen las busquedas,
    //entonces esto es obligatorio para poder encontrar el final
    clienteNombre=new char*[i+1]{}; //en este no afecta
    for (int j=0; j<i; j++) {
        clienteDNI[j]=buffdni[j];
        clienteNombre[j]=buffnom[j];
    }
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