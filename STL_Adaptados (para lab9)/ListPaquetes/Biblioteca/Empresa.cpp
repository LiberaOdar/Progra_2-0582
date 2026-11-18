//
// Created by cueva on 17/11/2026.
//

#include "Empresa.h"

#include "Especial.h"
#include "Estandar.h"

Empresa::Empresa() {

}

void Empresa::carga() {
    char tipo;
    ifstream arch("packages.csv", ios::in);
    if (not arch) {
        cout <<"No se abrir el archivo de paquetes.csv"<<endl;
        exit(1);
    }
    while (true) {
        Paquete *aux;
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo=='S')
            aux=new Estandar;
        else
            aux=new Especial;
        aux->lee(arch);
        lpaquetes.push_back(aux);
    }
    cargaproductos();
}

void Empresa::cargaproductos() {
    string codpaq;
    ifstream arch("products.csv", ios::in);
    if (not arch) {
        cout <<"No se abrir el archivo de productos.csv"<<endl;
        exit(1);
    }
    while (true) {
        Producto aux;
        getline(arch,codpaq,',');
        if (arch.eof()) break;
        aux.leeproductos(arch);
        for (list<Paquete*>::iterator it=lpaquetes.begin();
            it != lpaquetes.end();it++) {
            if ((*it)->get_codigo()==codpaq) {
                (*it)->cargapila(aux);
                break;
            }
        }
    }
}

void Empresa::descarga() {
    ofstream arch("reporte.txt", ios::out);
    if (not arch) {
        cout <<"No se abrir el archivo de reporte.txt"<<endl;
        exit(1);
    }
    while (not lpaquetes.empty()) {
        lpaquetes.front()->imprimir(arch,0,false);
        lpaquetes.pop_front();
        arch<<endl;
    }


}
