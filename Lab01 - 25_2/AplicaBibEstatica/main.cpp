#include <iostream>
#include "Biblioteca/Funciones.h"
#include "Biblioteca/Estructuras.h"


int main() {
    Alumnos arralumno[100]{};
    Cursos arrcurso[10]{};

    leealumnos(arralumno,"Alumnos.csv");
    leecursos(arrcurso,"Cursos.csv");
    leematricula(arrcurso,arralumno,"Matricula.csv");
    imprimecursos(arrcurso,"Reporte.txt");
    return 0;
}
