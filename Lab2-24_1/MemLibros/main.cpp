#include "Biblioteca/MetodoExactoMemoria.h"

int main() {
    char ***libros;
    int **stock,**pedidosClientes;

    lecturaDeLibros("Libros.csv",libros,stock);
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes);

    return 0;
}
