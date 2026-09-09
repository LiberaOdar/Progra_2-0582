#include <iostream>
#include "Biblioteca/Funciones.h"

int main() {
    int *arrcodigo;
    char **arrnombre;

    cargaclientes(arrcodigo,arrnombre,"Clientes.csv");

    return 0;
}
