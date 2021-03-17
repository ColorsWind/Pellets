//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_PELLET_H
#define PELLETS_PELLET_H


#include "../Vector.h"

class Pellet {

public:
    virtual void draw(QPainter* painter) = 0;

    virtual Location getLocation() const = 0;

    virtual Vector getVelocity() const = 0;

    virtual void move(double interval) = 0;
};


#endif //PELLETS_PELLET_H
