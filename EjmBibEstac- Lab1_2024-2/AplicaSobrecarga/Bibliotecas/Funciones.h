/*
* File:   Funciones.h
 * Author: cueva.r
 *
 * Created on 1 de abril de 2025, 08:45 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Estructuras.h"
    void leeplatos(Plato *arr,const char *nombre);
    void leerepartidor(Repartidor *arr,const char *nombre);
    void leepedido(Pedido *arr,const char *nombre);
    void cargayimprime(Pedido *arrped,Plato *arrpla,Repartidor *arrrepa,const char*nom);

#endif /* FUNCIONES_H */