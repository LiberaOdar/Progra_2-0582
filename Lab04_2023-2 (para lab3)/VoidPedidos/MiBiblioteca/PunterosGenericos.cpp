//
// Created by cueva.r on 9/09/2025.
//

#include "PunterosGenericos.h"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#define INC 5

using namespace std;


void cargaclientes(void*&clientes) {
    void*buffer[200],**lclientes;
    int i=0;
    ifstream arch("clientes2.csv",ios::in);
    if (!arch) {
        cout <<"No se puede abrir el archivo de clientes";
        exit(1);
    }
    while (1) {
        buffer[i]=leeclientes(arch);
        if (buffer[i]==nullptr)break;
        i++;
    }
    lclientes=new void*[i+1];
    for (int j=0;j<=i;j++)
        lclientes[j]=buffer[j];
    clientes=lclientes;
}

/*
79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
 */
void* leeclientes(ifstream &arch) {
    int *dni,telefono,cod;
    char*nombre,c;
    double *linea;
    void **reg;
    arch >> cod;
    if (arch.eof()) return nullptr;
    dni=new int;
    *dni=cod;
    arch.get();
    nombre=leecadena(arch,100,',');
    linea=new double;
    arch >> telefono >> c >> *linea;
    reg=new void*[4];

    reg[0]=dni;
    reg[1]=nombre;
    reg[2]=nullptr;
    reg[3]=linea;

    return reg;
}


/*
BIT-434,Campana Extractora modelo Glass,375.09,S
SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
 */
void cargaproductos(void*&productos) {
    void *buffer[200];
    void **lproductos;
    int i=0;
    ifstream arch("productos2.csv",ios::in);
    if (!arch) {
        cout <<"No se puede abrir el archivo de productos";
        exit(1);
    }
    while (1) {
        buffer[i]=leeproductos(arch);
        if (arch.eof()) break;
        i++;
    }
    lproductos=new void*[i+1];
    for (int j=0;j<=i;j++)
        lproductos[j]=buffer[j];

    productos=lproductos;
}

void *leeproductos(ifstream &arch) {
    char *codigo,*nombre,*tipo,c;
    double *precio;
    void **registro;

    codigo=leecadena(arch,10,',');
    if (arch.eof()) return nullptr;
    nombre=leecadena(arch,100,',');
    precio = new double;
    tipo = new char;
    arch >> *precio >> c >> *tipo;
    arch.get();

    registro=new void*[4];
    registro[0]=codigo;
    registro[1]=nombre;
    registro[2]=precio;
    registro[3]=tipo;

    return registro;
}
/*
JXD-139,50375303,6
 */
void cargapedidos(void *productos,void*clientes) {
    void**lclientes=(void**)clientes;
    char *codigo,c,tipo;
    int *dni,*cant,numdat[200]{},capa[200]{};
    double linea,*total;
    ifstream arch("pedidos2.csv",ios::in);
    if (!arch) {
        cout <<"No se puede abrir el archivo de pedidos";
        exit(1);
    }
    while (true) {
        codigo=leecadena(arch,10,',');
        if (arch.eof()) break;
        dni=new int;
        cant=new int;
        arch >> *dni >> c >> *cant;
        arch.get();
        int pos=buscacliente(*dni,clientes,linea);
        double precio=buscaprecio(codigo,productos,tipo);
        if (tipo=='N' or linea-precio*(*cant)>=0 ) {
            agregapedido(lclientes[pos],codigo,*cant,precio,numdat[pos],capa[pos]);
            // tarea modifica la línea del lcliente[pos]
        }
    }
}

void agregapedido(void *clientes,char *codigo,int cant,
    double precio,int &numdat,int &capa) {
    void **lclientes=(void**)clientes;
    if (numdat==capa)
        aumentarespacio(lclientes[2],numdat,capa);
    void **reg=new void*[3];
    reg[0]=codigo;
    int *auxcant=new int;
    *auxcant=cant;
    reg[1]=auxcant;
    double *auxtotal=new double;
    *auxtotal=cant*precio;
    reg[2]=auxtotal;
    void **lpedidos=(void**)lclientes[2];
    lpedidos[numdat-1]=reg;
    numdat++;
}

void aumentarespacio(void *&clientes,int &numdat,int &capa) {
    void **lclientes=(void**)clientes;
    capa+=INC;
    if (numdat==0) {
        lclientes=new void*[capa]{};
        numdat++;
    }
    else {
        void**laux=new void*[capa]{};
        for (int i=0;i<numdat;i++)
            laux[i]=lclientes[i];
        delete lclientes;
        lclientes=laux;
    }
    clientes=lclientes;
}


int buscacliente(int dni,void *clientes,double &credito) {
    void**lclientes=(void**)clientes;
    for (int i=0;lclientes[i];i++) {
        void **reg=(void**)lclientes[i];
        int *dniaux=(int*)reg[0];
        double *credaux=(double*)reg[3];
        if (dni==*dniaux) {
            credito=*credaux;
            return i;
        }
    }
    return -1;
}

double buscaprecio(char *codigo,void*productos,char&tipo) {
    void **lproductos=(void**)productos;
    for (int i=0;lproductos[i]!=nullptr;i++) {
        char*cod,*prodtipo;
        double *precio;
        void**reg=(void**)lproductos[i];
        cod=(char*)reg[0];
        if (strcmp(codigo,cod)==0) {
            precio=(double*)reg[2];
            prodtipo=(char*)reg[3];
            tipo=*prodtipo;
            return *precio;
        }
    }
    return 0.0;
}

char* leecadena(ifstream &arch,int max,char car) {
    char buff[max],*cad;
    arch.getline(buff,max,car);
    if (arch.eof()) return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeproductos(void *productos) {
    void**lproductos=(void**) productos;
    char *codigo,*nombre,*tipo;
    double *precio;
    ofstream arch("reporte.txt",ios::out);
    if (!arch) {
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }


    for(int i=0;lproductos[i]!=nullptr;i++) {
        void **reg=(void**) lproductos[i];
            codigo=(char*)reg[0];
            nombre=(char*)reg[1];
            precio=(double*)reg[2];
            tipo=(char*)reg[3];

        arch<<setw(10)<<codigo<<setw(50)<<nombre;
        arch<<setw(10)<<*precio<<setw(2)<<*tipo<<endl;
    }

}

void imprimeclientes(void *clientes) {
    void**lclientes=(void**) clientes;
    int *dni;
    char*nombre;
    double *linea;

    ofstream arch("reporte2.txt",ios::out);
    if (!arch) {
        cout <<"No se puede abrir el archivo de reporte2";
        exit(1);
    }
    for(int i=0;lclientes[i]!=nullptr;i++) {
        void**reg=(void**) lclientes[i];
        dni=(int*)reg[0];
        nombre=(char*)reg[1];
        linea=(double*)reg[3];
        arch<<setw(10)<<*dni<<setw(50)<<nombre<<setw(10)<<*linea<<endl;
        if (reg[2]!=nullptr)
            imprimepedidos(reg[2],arch);
    }
}

void imprimepedidos(void *pedidos,ofstream &arch) {
    char *codigo;
    int *cant;
    double *total;
    void**lpedidos=(void**)pedidos;

    for (int i=0;lpedidos[i];i++) {
        void**reg=(void**)lpedidos[i];
        codigo=(char*)reg[0];
        cant=(int*)reg[1];
        total=(double*)reg[2];
        arch<<setw(12)<<codigo<<left<<setw(5)<<*cant;
        arch<<setw(5)<<*total<<endl;
    }
}