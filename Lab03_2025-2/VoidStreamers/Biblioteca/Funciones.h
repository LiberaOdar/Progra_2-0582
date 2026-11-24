//
// Created by cueva.r on 15/09/2026.
//

#ifndef VOIDSTREAMERS_FUNCIONES_H
#define VOIDSTREAMERS_FUNCIONES_H
#include <fstream>
using namespace std;
    char*leecadena(ifstream& arch,int max,char carlim);
    void *leestreamers(ifstream &arch);
    void cargastreamers(void *&streamers);
    void *leecomentarios(ifstream &arch);
    void cargacomentarios(void *&comentarios);
    void imprimestreamers(void *streamers);
    void aumentarespacio(void *&strecome,int &num,int &capa);
    void buscacomentario(char *cuenta,void *comentarios,void *&strecome);
    void actualizacomentarios(void *streamers,void *comentarios);
    void imprimecomentarios(void *strecome,ofstream &arch);

#endif //VOIDSTREAMERS_FUNCIONES_H
