//
// Created by cueva.r on 21/10/2026.
//

#ifndef HERPLATOS_COMANDA_H
#define HERPLATOS_COMANDA_H
#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

class Comanda {
    private:
        int id;
        Bebida bebidas[20];
        Entrada  entradas[20];
        PlatoFondo platos_fondo[20];
        int cantidad_entradas;
        int cantidad_bebidas;
        int cantidad_platos_fondo;
        int hora_atencion;
        int tiempo_preparcion;
        double total;
        char *estado;
    public:
        Comanda();
        int get_id() const;
        void set_id(int id);
        int get_cantidad_entradas() const;
        void set_cantidad_entradas(int cantidad_entradas);
        int get_cantidad_bebidas() const;
        void set_cantidad_bebidas(int cantidad_bebidas);
        int get_cantidad_platos_fondo() const;
        void set_cantidad_platos_fondo(int cantidad_platos_fondo);
        int get_hora_atencion() const;
        void set_hora_atencion(int hora_atencion);
        int get_tiempo_preparcion() const;
        void set_tiempo_preparcion(int tiempo_preparcion);
        double get_total() const;
        void set_total(double total);
};


#endif //HERPLATOS_COMANDA_H
