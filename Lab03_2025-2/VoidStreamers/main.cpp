#include <iostream>

#include "Biblioteca/Funciones.h"

int main() {
    void *streamers,*comentarios;
    cargastreamers(streamers);
    cargacomentarios(comentarios);
    actualizacomentarios(streamers,comentarios);
    imprimestreamers(streamers);
    return 0;
}
