#include "Biblioteca/Funciones.h"

int main() {
    int *fechas;
    char****datosDeTexto;

    cargarInformacion("citas.csv",fechas,datosDeTexto);
    imprimefechas(fechas,datosDeTexto,"reporte.txt");
    return 0;
}
