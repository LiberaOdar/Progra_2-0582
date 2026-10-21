//
// Created by cueva.r on 21/10/2026.
//

#ifndef HERPLATOS_RESTAURANTE_H
#define HERPLATOS_RESTAURANTE_H
#include "Comanda.h"

class Restaurante {
    private:
        Comanda comandas[300];
        int cantidad_comandas;
    public:
        Restaurante();
        int get_cantidad_comandas() const;
        void set_cantidad_comandas(int cantidad_comandas);
        void cargar_comandas();

};


#endif //HERPLATOS_RESTAURANTE_H
