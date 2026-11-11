/* 
 * File:   Arbol.cpp
 * Author: cueva
 * 
 * Created on 18 de noviembre de 2022, 08:37 AM
 */
#include <iostream>
#include "Arbol.h"

using namespace std;

Arbol::Arbol() {
    raiz = NULL;
    
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
    delete raiz;
}

/*
Velocidad,DV001,Avenida A,5,60
Semaforo,DS473,Avenida B,10,true
Estacionamiento,DE467,Avenida C,15,false
 */
void Arbol::inserta(ifstream& arch) {
    
    char tipo[50];
    Nodo *nuevo,*rec;
    
    arch.getline(tipo,50,',');
    if(arch.eof()) return;
    nuevo = new Nodo;
    
    nuevo->asignamemoria(tipo);
    nuevo->leedron(arch);
    rec = raiz;
    
    while(rec){
        if(rec->cmp(*nuevo)){
            if(rec->izq==NULL){
                rec->izq = nuevo;
                break;
            }    
            else
                rec = rec->izq;
        }
        else{
            if(rec->der==NULL){
                rec->der = nuevo;
                break;
            }
            else    
                rec = rec->der;
        }
    }
    if(rec==NULL) raiz=nuevo;
}

void Arbol::enorden(ofstream&arch,Nodo* &parbol) {
    
    if(parbol==NULL) return;
    enorden(arch,parbol->izq);
    parbol->dron->imprimir(arch);
    enorden(arch,parbol->der);
}

void Arbol::recorre(Nodo*&parbol,int &n,char tipo,int valor){
    if(parbol==NULL) return;
    if(parbol->dron->gettipo()==tipo and n>0){
        parbol->dron->cambia(valor);
        n--;
    }
    recorre(parbol->izq,n,tipo,valor);
    recorre(parbol->der,n,tipo,valor);   
}

void Arbol::imprimerep(ofstream &arch) {
    enorden(arch,raiz);
}

int Arbol::cuenta(Nodo *ptr,char car){
    int cont=0;
    if(ptr->dron->gettipo()==car)
        cont++;
    if(ptr->izq!=nullptr)
        cont+=cuenta(ptr->izq,car);
    if(ptr->der!=nullptr)
        cont+=cuenta(ptr->der,car); 
    return cont;
}



void Arbol::actualiza(){
    int ne,ns;
//    cout << cuenta(raiz,'E')<<endl;
//    cout << cuenta(raiz,'S')<<endl;
    ne=cuenta(raiz,'E')*0.5;
    recorre(raiz,ne,'E',1);
    ns=cuenta(raiz,'S')*0.5;
    recorre(raiz,ns,'S',0);
}

