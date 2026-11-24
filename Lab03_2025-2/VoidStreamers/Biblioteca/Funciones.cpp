//
// Created by cueva.r on 15/09/2026.
//

#include "Funciones.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#define INC 5

using namespace std;

void cargastreamers(void *&streamers) {
    void *buffer[300]{},**lstreamers;
    ifstream arch("streamers.csv",ios::in);
    if (not arch) {
        cout<<"Error al abrir streamers.csv"<<endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        buffer[i] = leestreamers(arch);
        if (arch.eof()) break;
        i++;
    }
    lstreamers=new void*[i+1]{};
    for (int j=0;j<i;j++)
        lstreamers[j]=buffer[j];
    streamers=lstreamers;
}
//Rush,412717875,4731,542991,QR1018
void *leestreamers(ifstream &arch) {
    char *cuenta,*categoria,c;
    long long tiempo,promedio,*seguidores;

    cuenta=leecadena(arch,50,',');
    if (arch.eof())return nullptr;
    seguidores=new long long;
    arch>>tiempo>>c>>promedio>>c>>*seguidores>>c;
    categoria=leecadena(arch,50,'\n');
    void **registro=new void*[4];
    registro[0]=cuenta;
    registro[1]=seguidores;
    registro[2]=categoria;
    registro[3]=nullptr;
    return registro;
}
void cargacomentarios(void *&comentarios) {
    void *buffer[300]{},**lcomentarios;
    ifstream arch("comentarios.csv",ios::in);
    if (not arch) {
        cout<<"Error al abrir comentarios.csv"<<endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        buffer[i] = leecomentarios(arch);
        if (arch.eof())break;
        i++;
    }
    lcomentarios=new void*[i+1]{};
    for (int j=0;j<i;j++)
        lcomentarios[j]=buffer[j];
    comentarios=lcomentarios;
}
// ab7f2910,Can someone please help me understand [Castro_1021 loltyler1]
void *leecomentarios(ifstream &arch) {
    char *codigo,*texto,*emisor,*receptor;

    codigo=leecadena(arch,20,',');
    if (arch.eof())return nullptr;
    texto=leecadena(arch,100,'[');
    emisor=leecadena(arch,20,' ');
    receptor=leecadena(arch,20,']');
    arch.get();

    void**registro=new void*[4];
    registro[0]=codigo;
    registro[1]=emisor;
    registro[2]=receptor;
    registro[3]=texto;

    return registro;
}

void actualizacomentarios(void *streamers,void *comentarios) {
    char*cuenta;
    void **lstreamers=(void**)streamers; //no te olvides de mi
    for (int i=0;lstreamers[i];i++) {
        void **registro=(void**)lstreamers[i];
        cuenta=(char*)registro[0];
        buscacomentario(cuenta,comentarios,registro[3]);
        // void **lreg=(void**)registro[3];
        // cout<<"Hola";
    }
}

void buscacomentario(char *cuenta,void *comentarios,void *&strecome) {
    int numdata=0,numcapa=0;
    void**lcomentarios=(void**)comentarios;
    for (int i=0;lcomentarios[i];i++) {
        void **registro=(void**)lcomentarios[i];
        char *emisor=(char*)registro[1];

        if (strcmp(emisor,cuenta)==0) {
            if (numdata==numcapa)
                aumentarespacio(strecome,numdata,numcapa);
            char *receptor=(char*)registro[2];
            char *texto=(char*)registro[3];
            void **dupla=new void*[2];
            dupla[0]=receptor;
            dupla[1]=texto;
            void **lstrecome=(void**)strecome;
            lstrecome[numdata-1]=dupla;
            numdata++;
        }
    }
}

void aumentarespacio(void *&strecome,int &num,int &capa) {
    void**lstrecome=(void**)strecome;
    void **laux;
    capa+=INC;
    if (lstrecome==nullptr) {
        lstrecome=new void*[capa]{};
        num++;
    }
    else {
        laux=new void*[capa]{};
        for (int i=0;i<num;i++)
            laux[i]=lstrecome[i];
        delete lstrecome;
        lstrecome=laux;
    }
    strecome=lstrecome;
}

void imprimestreamers(void *streamers) {
    char *cuenta,*categoria;
    long long *seguidores;
    ofstream arch("reporte.txt",ios::out);
    if (not arch) {
        cout<<"Error al abrir Reporte.txt"<<endl;
        exit(1);
    }
    void **lstreamers=(void**)streamers;
    for (int i=0;lstreamers[i];i++) {
        void **lregistro=(void**)lstreamers[i];
        cuenta=(char*)lregistro[0];
        seguidores=(long long*)lregistro[1];
        categoria=(char*)lregistro[2];
        arch<<left<<setw(20)<<cuenta<<setw(20)<<*seguidores<<setw(20)<<categoria<<endl;
        if (lregistro[3]!=nullptr)
            imprimecomentarios(lregistro[3],arch);
    }
}
void imprimecomentarios(void *strecome,ofstream &arch) {
    void **lstrecome=(void**)strecome;

    for (int i=0;lstrecome[i];i++) {
        void**ldupla=(void**)lstrecome[i];
        char *receptor=(char*)ldupla[0];
        char *texto=(char*)ldupla[1];
        arch<<setw(20)<<receptor<<setw(20)<<texto<<endl;
    }
    arch<<endl;
}


char*leecadena(ifstream& arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}