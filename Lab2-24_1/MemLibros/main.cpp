#include "Biblioteca/MetodoExactoMemoria.h"

int main() {
    char ***libros;
    int **stock;

    lecturaDeLibros("Libros.csv",libros,stock);

    return 0;
}
