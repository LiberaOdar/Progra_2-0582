//
// Created by cueva.r on 18/09/2026.
//

#include "BibliotecaEnteros.h"

#include <iostream>

using namespace std;

void *leenum(ifstream&arch) {
    int num;
    arch>>num;
    if (arch.eof()) return nullptr;
    int *pnum=new int;
    *pnum=num;
    return pnum;
}

int comparanum(const void *a, const void *b) {
    void **pa, **pb;
    int *ai,*bi;
    pa=(void **)a;
    pb=(void **)b;
    ai=(int *)pa[0];
    bi=(int *)pb[0];

    return *bi-*ai;
}

void imprimenum(ofstream&arch,void*dato) {
    void**ldato=(void**)dato;
    int *num;
    num=(int*)ldato;
    arch<<*num<<endl;
}