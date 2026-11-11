//
// Created by Erasmo on 11/06/25.
//

#ifndef L7DRONES_DRONEVELOCIDAD_HPP
#define L7DRONES_DRONEVELOCIDAD_HPP
#include "Drone.hpp"

class DroneVelocidad : public Drone {
private:
    int velocidad_maxima_permitida;
public:
    int getVelocidadMaximaPermitida() const;
    void setVelocidadMaximaPermitida(int );
    void leer(ifstream &input);
    void imprimir(ofstream &) const;
    char gettipo();
    void cambia(int){};
};


#endif //L7DRONES_DRONEVELOCIDAD_HPP
