//
// Created by cueva.r on 18/09/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAENTEROS_H
#define LISTAGENERICA_BIBLIOTECAENTEROS_H
#include<fstream>
using namespace std;
    void *leenum(ifstream&arch);
    int comparanum(const void *a, const void *b);
    void imprimenum(ofstream&arch,void*dato);
#endif //LISTAGENERICA_BIBLIOTECAENTEROS_H
