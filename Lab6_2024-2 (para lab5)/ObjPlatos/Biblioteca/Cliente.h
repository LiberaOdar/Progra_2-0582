//
// Created by cueva.r on 30/09/2026.
//

#ifndef OBJPLATOS_CLIENTE_H
#define OBJPLATOS_CLIENTE_H
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalpagado;
public:
    Cliente();
    ~Cliente();
    //Cliente(Cliente &);
    int get_dni() const;
    void set_dni(int dni);
    double get_descuento() const;
    void set_descuento(double descuento);
    double get_totalpagado() const;
    void set_totalpagado(double totalpagado);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void set_distrito(const char *);
    void get_distrito(char *);
    void lee_cliente(ifstream &);
    void imprime_cliente(ofstream &);
    void asigna(Cliente &);
    // miscelania.....
    void libera();
};


#endif //OBJPLATOS_CLIENTE_H
