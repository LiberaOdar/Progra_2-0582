//
// Created by cueva.r on 3/11/2026.
//

#include "Cola.h"

Cola::Cola() {
    longitud=0;
    cabeza=nullptr;
    cola=nullptr;
}

void Cola::encola(DetallaComanda &aux) {
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = aux;
    if (longitud==0) {
        cola=nuevo;
        cabeza=nuevo;
    }
    else {
        cola->sig=nuevo;
        cola=nuevo;
    }
    longitud++;
}

void Cola::desencola(DetallaComanda &aux) {
    if (longitud!=0) {
        aux=cabeza->dato;
        if (cabeza==cola)cola=nullptr;
        cabeza=cabeza->sig;
    }
    longitud--;

}
