#include "Biblioteca/BibliotecaGenerica.h"
#include "Biblioteca/BibliotecaEnteros.h"
#include "Biblioteca/BibliotecaRegistro.h"

#define MAX 300

int main() {
    void*arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1,*lista2;

    procesaArreglo(arreglo1,leenum,"numeros1.txt");
    creaLista(arreglo1,lista1,comparanum);
    procesaArreglo(arreglo2,leenum,"numeros2.txt");
    creaLista(arreglo2,lista2,comparanum);
    imprimeLista(lista1,imprimenum,"reporte.txt");

    procesaArreglo(arreglo1,leeregistro,"atenciones1.csv");
    creaLista(arreglo1,lista1,comparareg);
    imprimeLista(lista1,imprimeregistro,"reportereg.txt");

    return 0;
}
