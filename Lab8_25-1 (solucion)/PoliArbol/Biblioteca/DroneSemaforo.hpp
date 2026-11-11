//
// Created by Erasmo on 11/06/25.
//

#ifndef L7DRONES_DRONESEMAFORO_HPP
#define L7DRONES_DRONESEMAFORO_HPP

#include "Drone.hpp"

class DroneSemaforo : public Drone {
private:
    int ConCamaraRoja;
public:
    int getConCamaraRoja() const;
    void setConCamaraRoja(int );
    void leer(ifstream &);
    void imprimir(ofstream &) const;
    char gettipo();
    void cambia(int);
};


#endif //L7DRONES_DRONESEMAFORO_HPP
