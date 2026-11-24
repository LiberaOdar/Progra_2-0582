//
// Created by cueva.r on 20/10/2026.
//

#ifndef HERPLATOS_PRODUCTO_H
#define HERPLATOS_PRODUCTO_H
#include <fstream>

using namespace std;

class Producto {
private:
    char *nombre;
    double precio;
public:
    Producto();
    ~Producto();
    double get_precio() const;
    void set_precio(double precio);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void leeproducto(ifstream &);
    void imprimeproducto(ofstream &,double&);
};


#endif //HERPLATOS_PRODUCTO_H
