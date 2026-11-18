//
// Created by cueva.r on 17/11/2026.
//

#ifndef STL_ESTANTE_ESTANTE_H
#define STL_ESTANTE_ESTANTE_H
#include <fstream>
using namespace std;

class Estante {
public:
    char get_tipo() const;

    void set_tipo(char tipo);

    int get_id() const;

    void set_id(int id);

    double get_capacidad() const;

    void set_capacidad(double capacidad);

private:
        char tipo;
        int id;
        double capacidad;

    public:
        Estante();
        void leestante(ifstream &);
        bool operator<(const Estante&)const;
};


#endif //STL_ESTANTE_ESTANTE_H
