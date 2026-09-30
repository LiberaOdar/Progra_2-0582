//
// Created by cueva.r on 30/09/2026.
//

#include <iostream>
#include "ListaconEnteros.h"

using namespace std;

void*leenumeros(ifstream &arch) {
    int num,*pnum;
    arch >> num;
    if (arch.eof())return nullptr;
    pnum = new int;
    *pnum = num;
    return pnum;
}
