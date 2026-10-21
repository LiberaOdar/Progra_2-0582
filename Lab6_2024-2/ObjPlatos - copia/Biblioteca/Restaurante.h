//
// Created by cueva.r on 6/10/2026.
//

#ifndef OBJPLATOS_RESTAURANTE_H
#define OBJPLATOS_RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"


class Restaurante {
    private:
        Cliente clientes[200];
        int cantDeClientes;
        Plato platos[200];
        int cantDePlatos;
        void procesaplatos(int,ifstream &);
        int buscacliente(int);
        int buscaplato(char*);
        void actualizatodo(int, int,int);
    public:
        Restaurante();
        void cargaclientes(const char *);
        void borracliente();
        void cargaplatos(const char *);
        void imprimirclientes(const char *);
        void procesapedidos(const char *);

};


#endif //OBJPLATOS_RESTAURANTE_H
