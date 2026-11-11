//
// Created by cueva.r on 20/10/2026.
//

#ifndef HERPLATOS_PRODUCTO_H
#define HERPLATOS_PRODUCTO_H
#include <fstream>

using namespace std;

class Producto {
private:
    string codigo;
    char *nombre;
    double precio;
public:
    Producto();
    ~Producto();
    Producto(const Producto&);
    double get_precio() const;
    void set_precio(double precio);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    bool lee(ifstream &);
    void imprime(ofstream &);
    string get_codigo() const;
    void set_codigo(const string &codigo);
    void operator= (const Producto &orig);
};


#endif //HERPLATOS_PRODUCTO_H
