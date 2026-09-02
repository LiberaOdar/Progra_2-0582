#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/Funciones.h"


int main() {
    Plato arrplato[200];
    Repartidor arrrepa[200];
    Pedido arrpedi[200];

    leeplatos(arrplato,"ArchivosDeEntrada/PlatosOfrecidos.csv");
    leerepartidor(arrrepa,"ArchivosDeEntrada/RepartidoresContratados.csv");
    leepedido(arrpedi,"ArchivosDeEntrada/OrdenesDeCompra.txt");
    cargayimprime(arrpedi,arrplato,arrrepa,"ArchivosDeSalida/Reporte.txt");
}
