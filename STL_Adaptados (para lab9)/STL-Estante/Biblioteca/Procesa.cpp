//
// Created by cueva.r on 17/11/2026.
//
#include <fstream>
#include "Procesa.h"

using namespace std;

Procesa::Procesa() {

}

void Procesa::carga() {
    ifstream arch("Estantes2.csv",ios::in);
    if(not arch) {
        cout << "No se puede abrir el archivo de estantes"<<endl;
        exit(1);
    }
    while(true) {
        Estante aux;
        vector<Libro> vlibros;
        aux.leestante(arch);
        if (arch.eof()) break;
        mestante[aux]=vlibros;
    }
    cargalibros();
}

void Procesa::cargalibros() {
    ifstream arch("Libros4.csv",ios::in);
    if(not arch) {
        cout << "No se puede abrir el archivo de libros"<<endl;
        exit(1);
    }
    while(true) {
        Libro aux;
        aux.leelibro(arch);
        if (arch.eof()) break;
        for (map<Estante,vector<Libro> >::iterator it=mestante.begin();
            it != mestante.end(); it++) {
            double capa=it->first.get_capacidad();
            double total=0;
            for (int i=0;i<it->second.size();i++) {
                total+=it->second[i].get_peso();
            }
            if (capa>=total+aux.get_peso()) {
                it->second.push_back(aux);
                break;
            }
        }
    }
}
