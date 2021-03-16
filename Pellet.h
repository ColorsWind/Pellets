//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_PELLET_H
#define PELLETS_PELLET_H


#include "Vector.h"

class Pellet {
    virtual Point location() const = 0;

    virtual void draw() const = 0;

    virtual Vector velocity() const = 0;

};


#endif //PELLETS_PELLET_H
