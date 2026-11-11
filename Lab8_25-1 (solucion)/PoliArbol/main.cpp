#include "Biblioteca/Central.h"

int main(int argc, char** argv) {
    Central cdrones;

    cdrones.carga();
    cdrones.actualiza();
    cdrones.muestra();

    return 0;
}