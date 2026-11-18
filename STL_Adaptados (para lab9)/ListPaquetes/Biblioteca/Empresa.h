//
// Created by cueva on 17/11/2026.
//

#ifndef LISTEMPAQUES_EMPRESA_H
#define LISTEMPAQUES_EMPRESA_H
#include <list>

#include "Paquete.h"


class Empresa {
private:
    list<Paquete*> lpaquetes;
    void cargaproductos();
public:
    Empresa();
    void carga();
    void descarga();
};


#endif //LISTEMPAQUES_EMPRESA_H
