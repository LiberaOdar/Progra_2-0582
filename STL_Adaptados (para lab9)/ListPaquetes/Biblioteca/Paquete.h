//
// Created by cueva on 17/11/2026.
//

#ifndef LISTEMPAQUES_PAQUETE_H
#define LISTEMPAQUES_PAQUETE_H
#include "Producto.h"
#include <vector>
#include <fstream>
using namespace std;

class Paquete {
    private:
        string codigo;
        double distancia;
        int cantidad;
        vector<Producto>vpila;
    public:
        Paquete();
        string get_codigo() const;
        void set_codigo(const string &codigo);
        double get_distancia() const;
        void set_distancia(double distancia);
        int get_cantidad() const;
        void set_cantidad(int cantidad);
        void cargapila(Producto&);
        virtual void lee(ifstream &);
        virtual void imprimir(ofstream &,double,bool);
};


#endif //LISTEMPAQUES_PAQUETE_H
