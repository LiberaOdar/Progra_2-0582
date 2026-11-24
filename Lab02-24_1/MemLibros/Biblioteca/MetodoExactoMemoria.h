//
// Created by cueva.r on 26/08/2026.
//

#ifndef MEMLIBROS_METODOEXACTOMEMORIA_H
#define MEMLIBROS_METODOEXACTOMEMORIA_H
#include <fstream>
    using namespace std;
    char*leecadena(ifstream& arch,int max,char carlim);
    int* leestock(ifstream& arch);
    void lecturaDeLibros(const char * nom,char ***&libros,
        int **&stock);
    char **leelibro(ifstream& arch);
    int buscacliente(int dni,int **pedidosClientes);
    void asignarpedidocliente(int codpedido,int *clientes);
    void asignarpedidos(int dni,int **pedidosClientes,
        int codpedido);
    void atencionDePedidos(const char *nom,char ***libros,int **stock,
        int **&pedidosClientes);
#endif //MEMLIBROS_METODOEXACTOMEMORIA_H
