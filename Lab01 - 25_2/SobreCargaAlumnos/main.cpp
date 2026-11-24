#include <iostream>
#include <fstream>
#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/Sobrecargas.h"

using namespace std;

int main() {
    Alumnos alu;
    Cursos cur;

    ifstream arch("Alumnos.csv",ios::in);
    if (!arch) {
        cout <<"No se puede abrir alumnos";
        exit(1);
    }
    arch >> alu;
    ifstream archcur("Cursos.csv",ios::in);
    if (!archcur) {
        cout <<"No se puede abrir cursos";
        exit(1);
    }
    archcur >> cur;
    cur+=alu;  //insertando al alumno
    cur++;  //procesando los tipos de alumno
    ofstream rep("reporte.txt",ios::out);
    if (!rep) {
        cout <<"No se puede abrir reporte";
        exit(1);
    }
    rep<<cur; //imprimiendo

    return 0;
}
