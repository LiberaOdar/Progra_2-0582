//
// Created by Erasmo on 10/06/25.
//

#ifndef L7DRONES_DRONE_HPP
#define L7DRONES_DRONE_HPP
#include <fstream>

using namespace std;

class Drone {
public:
    Drone();
    virtual ~Drone();
    virtual void leer(ifstream &);
    virtual void imprimir(ofstream &) const;
    void getId(char *) const;
    void setId(const char *);
    void getUbicacion(char *) const;
    void setUbicacion(const char *);
    int getCapacidad() const;
    void setCapacidad(int);
    virtual char gettipo()=0;
    virtual void cambia(int)=0;
private:
    char *id;
    char *ubicacion;
    int capacidad;

};


#endif //L7DRONES_DRONE_HPP
