#include <iostream>
#include "MiBiblioteca/PunterosGenericos.h"

using namespace std;

int main() {
    void *productos,*clientes;
    cargaproductos(productos);
    imprimeproductos(productos);
    cargaclientes(clientes);
    imprimeclientes(clientes);
    cargapedidos(productos,clientes);
    imprimeclientes(clientes);
    return 0;
}