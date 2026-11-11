//
// Created by cueva.r on 28/10/2026.
//

#ifndef POLIPLATOS_DETALLACOMANDA_H
#define POLIPLATOS_DETALLACOMANDA_H
#include "Producto.h"
#include <fstream>

using namespace std;

class DetallaComanda {
private:
    int id;
    Producto *pedido;
public:
    DetallaComanda();
    ~DetallaComanda();
    int get_id() const;
    void set_id(int id);
    void asignatipo(int,ifstream &);
    void operator =(const DetallaComanda &);
    char eles();
    void imprimecomanda(ofstream &);
    static bool compara(const DetallaComanda &,const DetallaComanda &);
};


#endif //POLIPLATOS_DETALLACOMANDA_H
