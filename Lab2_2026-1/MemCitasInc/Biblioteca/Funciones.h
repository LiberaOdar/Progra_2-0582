//
// Created by cueva.r on 9/09/2026.
//

#ifndef MEMCITASINC_FUNCIONES_H
#define MEMCITASINC_FUNCIONES_H
#include <fstream>
using namespace std;
    void agregadatos(ifstream &arch,char ***&datos,int &capa,
        int &num);
    void aumentarespacio(int *&fechas, char ****&datosDeTexto,
        int &capa,int &num);
    void cargarInformacion(const char *nom,
        int *&fechas,char ****&datosDeTexto);
    int buscafecha(int fecha,int *arrfechas);
    void insertafechas(int fecha,int *&arrfechas,
        char ****&datosDeTexto,int &capacidad,int &numdatos,int &pos);
    char*leecadena(ifstream& arch,int max,char carlim);
    void aumentarhorizontal(char ***&datosDeTexto,
        int &capa,int &num);
    void cargarInformacion(const char *nom,
        int *&fechas,char ****&datosDeTexto);
    void imprimefechas(int *fechas,char ****datos,
        const char *nombre);
#endif //MEMCITASINC_FUNCIONES_H
