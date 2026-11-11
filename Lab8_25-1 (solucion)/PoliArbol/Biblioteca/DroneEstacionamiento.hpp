//
// Created by Erasmo on 11/06/25.
//

#ifndef L7DRONES_DRONEESTACIONAMIENTO_HPP
#define L7DRONES_DRONEESTACIONAMIENTO_HPP

#include "Drone.hpp"

class DroneEstacionamiento : public Drone {
private:
    int zona_carga;
public:
    int getZonaCarga() const;
    void setZonaCarga(int zonaCarga);
    void leer(ifstream &);
    void imprimir(ofstream &) const;
    char gettipo();
    void cambia(int);
};


#endif //L7DRONES_DRONEESTACIONAMIENTO_HPP
