/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SobreCarga.cpp
 * Author: cueva
 *
 * Created on 21 de marzo de 2025, 08:31 AM
 */

#include "SobreCarga.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
/*
AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
AP-410,ANTICUCHO,12.90,APERITIVO
*/
ifstream &operator >>(ifstream &in,Plato &a){
    char tipo[50];

    in.getline(a.codigo,10,',');
    in.getline(a.nombre,60,',');
    in >> a.precio;
    in.get();
    in.getline(tipo,50);
    a.totalDePedidos=0;
    a.totalRecaudado=0;

    return in;
}

/*
JNV387,Justino Norabuena Virginia Karina,Motocicleta
PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
 */

ifstream &operator >>(ifstream &in,Repartidor &a){

    in.getline(a.codigo,10,',');
    in.getline(a.nombre,50,',');
    in.getline(a.tipoDeVehiculo,15);
    a.cantidadDeOrdenes=0;
    a.pagoPorEntregas=0;

    return in;
}

/*
 15290194  BR-283    1    MCE193    11.69
 80694546     BE-987    2    SRY667    1.01
 */
ifstream &operator >>(ifstream &in,Pedido &a){
    in >> a.dniDelCliente;
    in >> a.codigoDelPlato;
    in >> a.cantidad;
    in >> a.codigoDelRepartidor;
    in >> a.distanciaARecorrer;
    a.precio=0;

    return in;
}


bool operator <=(Pedido &ped,Plato *arrp ){

    for(int i=0;strcmp(arrp[i].codigo,"FIN")!=0;i++)
    {
        if(strcmp(arrp[i].codigo,ped.codigoDelPlato)==0){
            ped.precio+=arrp[i].precio;
            arrp[i].totalDePedidos+=ped.cantidad;
            arrp[i].totalRecaudado= arrp[i].precio*arrp[i].totalDePedidos;
            return true;
        }
    }
    return false;

}


void operator<=(Repartidor *arrRepartidores,const Pedido &pedido){
    for(int i=0;strcmp(arrRepartidores[i].codigo,"FIN")!=0;i++){
        if(strcmp(arrRepartidores[i].codigo,pedido.codigoDelRepartidor)==0){
            bool encontradoCliente=false;
            for(int j=0;j<arrRepartidores[i].cantidadDeOrdenes;j++){
                if(arrRepartidores[i].ordenesDeCompra[j].dniDelCliente==pedido.dniDelCliente){
                    bool encontroPlato=false;
                    for(int k=0;k<arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos;k++){
                        if(strcmp(arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[k].codigo,pedido.codigoDelPlato)==0){
                            arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[k].cantidad+=pedido.cantidad;
                            encontroPlato=true;
                            break;
                        }
                    }
                    if(!encontroPlato){
                        arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos].cantidad=pedido.cantidad;
                        arrRepartidores[i].ordenesDeCompra[j].platosSolicitados[arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos].precio=pedido.precio;
                        arrRepartidores[i].ordenesDeCompra[j].cantidadDePlatos++;
                    }
                    encontradoCliente=true;
                    break;
                }
            }
            if(!encontradoCliente){
                arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].dniDelCliente=pedido.dniDelCliente;
                arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].platosSolicitados[arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].cantidadDePlatos].cantidad=pedido.cantidad;
                arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].platosSolicitados[arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].cantidadDePlatos].precio=pedido.precio;
                strcpy(arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].platosSolicitados[arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].cantidadDePlatos].codigo,pedido.codigoDelPlato);
                arrRepartidores[i].ordenesDeCompra[arrRepartidores[i].cantidadDeOrdenes].cantidadDePlatos++;
                arrRepartidores[i].cantidadDeOrdenes++;

            }
        }
    }
}

void operator !(OrdenDeCompra &orden){
    if(orden.distancia<8){
        orden.pagoPorEnvio=10.5;
    } else if(orden.distancia>=8 and orden.distancia<12){
        orden.pagoPorEnvio=14.8;
    } else if(orden.distancia>=12 and orden.distancia<20){
        orden.pagoPorEnvio=23.6;
    } else if(orden.distancia>=20){
        orden.pagoPorEnvio=31.7;
    }
}

void operator !(Repartidor &rep){
    for(int i=0;i<rep.cantidadDeOrdenes;i++){
        rep.pagoPorEntregas+=rep.ordenesDeCompra[i].montoPorCobrar;
    }
}

ofstream& operator <<(ofstream &arch,Plato a){
    char cad[100];

    arch <<setw(10)<< a.codigo<<setw(50)<< a.nombre
            <<setprecision(2) << fixed << setw(10) << a.precio
            <<setw(5)<< a.totalDePedidos
            <<setw(5)<< a.totalRecaudado;
    return arch;
}

void operator <<(ofstream &arch,const Repartidor &repartidor){
    arch<<left<<setw(10)<<repartidor.codigo<<setw(50)<<repartidor.nombre<<setw(20)<<repartidor.tipoDeVehiculo<<right<<setprecision(2)<<fixed<<setw(15)<<repartidor.pagoPorEntregas<<endl;
    arch<<"ORDENES ENTREGADAS"<<endl;
    for(int i=0;i<repartidor.cantidadDeOrdenes;i++){
        arch<<right<<setw(15)<<repartidor.ordenesDeCompra[i].dniDelCliente<<setprecision(2)<<fixed<<setw(8)<<repartidor.ordenesDeCompra[i].distancia<<setw(12)<<repartidor.ordenesDeCompra[i].montoPorCobrar<<setw(10)<<repartidor.ordenesDeCompra[i].pagoPorEnvio<<endl;
        arch<<setw(7)<<' '<<"Platos solicitados:"<<endl;
        for(int j=0;j<repartidor.ordenesDeCompra[i].cantidadDePlatos;j++){
            double totalPlatoPedido=repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad*repartidor.ordenesDeCompra[i].platosSolicitados[j].precio;
            arch<<setw(7)<<' '<<"- "<<left<<setw(9)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].codigo<<right<<setprecision(2)<<fixed<<setw(8)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].precio<<setw(8)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad<<setw(10)<<totalPlatoPedido<<endl;
        }
        arch<<endl;
    }
}