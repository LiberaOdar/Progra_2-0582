//
// Created by uveag on 30/09/2026.
//

#include "ListaconEnteros.h"
#include <iostream>
#include <fstream>
using namespace std;

void *leenumeros(ifstream &arch) {
    int num, *pnum;
    arch>>num;
    if (arch.eof()) return nullptr;
    pnum = new int;
    *pnum = num;
    return pnum;
}
