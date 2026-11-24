//
// Created by cueva.r on 9/09/2025.
//

#ifndef VOIDPEDIDOS_PUNTEROSGENERICOS_H
#define VOIDPEDIDOS_PUNTEROSGENERICOS_H
    #include <fstream>
    using namespace std;

    char* leecadena(ifstream &arch,int max,char car);
    void *leeproductos(ifstream &arch);
    void cargaproductos(void*&productos);
    void imprimeproductos(void *productos);
    void* leeclientes(ifstream &arch);
    void cargaclientes(void*&clientes);
    void imprimeclientes(void *clientes);
    int buscacliente(int dni,void*clientes,double &);
    double buscaprecio(char *codigo,void*productos,char&tipo);
    void cargapedidos(void *productos,void*clientes);
    void aumentarespacio(void *&clientes,int &numdat,int &capa);
    void agregapedido(void *clientes,char *codigo,int cant,
        double precio,int &numdat,int &capa);
    void imprimepedidos(void *pedidos,ofstream &arch);
#endif //VOIDPEDIDOS_PUNTEROSGENERICOS_H