
/* 
 * File:   ColaconRegistros.h
 * Author: cueva
 *
 * Created on 8 de octubre de 2024, 07:38 AM
 */

#ifndef COLACONREGISTROS_H
#define COLACONREGISTROS_H
#include <fstream>
using namespace std;
    void *leeregistros(ifstream &arch);
    char *leerCadena(ifstream &arch, int n, char c);
    void imprimeregistros(ofstream &arch,void *nodo);
    void *leeordenes(ifstream &arch);
    bool compruebaregistro(void*a,void*b);
#endif /* COLACONREGISTROS_H */
