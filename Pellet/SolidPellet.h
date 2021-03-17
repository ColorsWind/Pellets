//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_SOLIDPELLET_H
#define PELLETS_SOLIDPELLET_H


#include <QPainter>
#include "Pellet.h"

class SolidPellet : public Pellet {
private:
    Point location;
    Vector velocity;
public:
    SolidPellet(const Point &initial, const Vector &velocity);

    Point getLocation() const override;

    void draw(QPainter *painter) override;

    Vector getVelocity() const override;
};


#endif //PELLETS_SOLIDPELLET_H
