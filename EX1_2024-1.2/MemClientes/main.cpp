#include "Biblioteca/Funciones.h"



int main() {
    int *clienteDNI;
    char **clienteNombre;

    cargarClientes(clienteDNI,clienteNombre,"Clientes.csv");


    return 0;
}
