/*
* To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SobreCarga.h
 * Author: cueva
 *
 * Created on 21 de marzo de 2025, 08:31 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <fstream>
#include "Estructuras.h"
using namespace std;

      ifstream &operator >>(ifstream &in,Plato &a);
      ifstream &operator >>(ifstream &in,Repartidor &a);
      ifstream &operator >>(ifstream &in,Pedido &a);
      bool operator <=(Pedido &ped,Plato *arrp );
      ofstream& operator <<(ofstream &arch,Plato a);
      void operator<=(Repartidor *arrRepartidores,const Pedido &pedido);
      void operator !(OrdenDeCompra &orden);
      void operator !(Repartidor &rep);
      void operator <<(ofstream &arch,const Repartidor &repartidor);
#endif /* SOBRECARGA_H */
