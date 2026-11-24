//
// Created by cueva.r on 22/09/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAREGISTRO_H
#define LISTAGENERICA_BIBLIOTECAREGISTRO_H
#include <fstream>
using namespace std;
    char*leecadena(ifstream& arch,int max,char carlim);
    void* leeregistro(ifstream &arch);
    int comparareg(const void *a,const void *b);
    void imprimeregistro(ofstream &arch,void*dato);


#endif //LISTAGENERICA_BIBLIOTECAREGISTRO_H
