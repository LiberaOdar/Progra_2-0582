/* 
 * File:   Central.h
 * Author: cueva
 *
 * Created on 18 de junio de 2025, 06:14 PM
 */

#ifndef CENTRAL_H
#define CENTRAL_H

#include "Arbol.h"


class Central {
public:
    Central();
    Central(const Central& orig);
    virtual ~Central();
    void carga();
    void muestra();
    void actualiza();
private:
    Arbol ADrones;
};

#endif /* CENTRAL_H */

