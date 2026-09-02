#include <iostream>
#include <cstring>
#include <fstream>
#include "Biblioteca/Estructuras.h"
#include "Biblioteca/Sobrecarga.h"

using namespace std;

int main() {
    Plato strplato;
    Pedido strped;
    Repartidor arrrepa[5];

    ifstream fplato("ArchivosDeEntrada/PlatosOfrecidos.csv",ios::in);
    if (!fplato) {
        cout<<"No se puede abrir el archivo de entrada"<<endl;
        exit(1);
    }
    ofstream fsalida("ArchivosDeSalida/Reporte.txt",ios::out);
    ifstream fpedido("ArchivosDeEntrada/OrdenesDeCompra.txt",ios::in);
    if (!fpedido) {
        cout<<"No se puede abrir el archivo de entrada"<<endl;
        exit(1);
    }
    fplato >> strplato;
    fpedido >> strped;
    fsalida << strplato;

    ifstream frepa("ArchivosDeEntrada/RepartidoresContratados.csv",ios::in);
    if (!frepa) {
        cout<<"No se puede abrir el archivo de entrada"<<endl;
        exit(1);
    }
    frepa >> arrrepa[0];
    frepa >> arrrepa[1];
    frepa >> arrrepa[2];
    strcpy(arrrepa[3].codigo,"FIN");
    arrrepa<=strped;
    return 0;
}