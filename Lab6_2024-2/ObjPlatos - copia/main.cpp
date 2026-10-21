#include "Biblioteca/Restaurante.h"

int main() {
    Restaurante rest;
    rest.cargaclientes("clientes.csv");
    rest.cargaplatos("PlatosOfrecidos.csv");
    rest.procesapedidos("Pedidos.csv");
    rest.imprimirclientes("ReporteClie.txt");


    return 0;
}
