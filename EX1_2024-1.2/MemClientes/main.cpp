#include <iostream>
#include "Bibllioteca/Funciones.h"

int main() {
    int *clienteDNI;
    char **clienteNombre;
    cargarClientes(clienteDNI, clienteNombre, "ArchivosDeDatos/Clientes.csv");
    return 0;
}
