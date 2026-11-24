
/* 
 * File:   Nodo.h
 * Author: cueva
 *
 * Created on 18 de noviembre de 2022, 08:28 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
#include "Drone.hpp"

using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
    void leedron(ifstream&);
    void impdron(ofstream&);
    void actdron();
    int cmp(Nodo &);
    int valor();
    void asignamemoria(char *);
private:
    Drone * dron;
    Nodo *izq;
    Nodo *der;
};

#endif /* NODO_H */

