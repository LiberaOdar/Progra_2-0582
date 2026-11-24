/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: cueva
 *
 * Created on 18 de noviembre de 2022, 08:37 AM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

#include <fstream>

using namespace std;

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void inserta(ifstream &);
    void imprimerep(ofstream &);
    void actualiza();
private:
    void enorden(ofstream &,Nodo *&);
    int cuenta(Nodo*,char);
    void recorre(Nodo*&,int&,char,int);
    
    Nodo *raiz;
};

#endif /* ARBOL_H */

