//
// Created by cueva.r on 17/11/2026.
//

#ifndef STL_ESTANTE_LIBRO_H
#define STL_ESTANTE_LIBRO_H
#include <iostream>
#include <fstream>
using namespace std;

class Libro {
    public:
    Libro();
    int get_paginas() const;
    void set_paginas(int paginas);
    double get_peso() const;
    void set_peso(double peso);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    void leelibro(ifstream &);
private:
        string nombre;
        int paginas;
        double peso;
};


#endif //STL_ESTANTE_LIBRO_H
