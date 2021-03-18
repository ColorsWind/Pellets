//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_PELLET_H
#define PELLETS_PELLET_H


#include "../Vector.h"
#include "PelletItem.h"

class Pellet {

public:
    virtual void draw(QGraphicsScene *scene) = 0;

    virtual void remove(QGraphicsScene *scene) = 0;

    virtual void update(QGraphicsScene *scene) = 0;

    virtual Location getLocation() const = 0;

    virtual Vector getVelocity() const = 0;

    virtual void reflectY() = 0;

    virtual void reflectX() = 0;

    virtual void move(double interval) = 0;

    virtual const PelletItem* getItem() const = 0;
};


#endif //PELLETS_PELLET_H
