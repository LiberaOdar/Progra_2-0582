//
// Created by cueva on 17/11/2026.
//

#ifndef LISTEMPAQUES_PRODUCTO_H
#define LISTEMPAQUES_PRODUCTO_H
#include <iostream>
#include <fstream>
using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    double peso;
    double valor;
public:
    Producto();
    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    double get_peso() const;
    void set_peso(double peso);
    double get_valor() const;
    void set_valor(double valor);
    void leeproductos(ifstream &);
    void imprimeproductos(ofstream &);

};


#endif //LISTEMPAQUES_PRODUCTO_H
