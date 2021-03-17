//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_SOLIDPELLET_H
#define PELLETS_SOLIDPELLET_H


#include <QPainter>
#include <QGraphicsScene>
#include "Pellet.h"
#include "../Location.h"

class SolidPellet : public Pellet {
private:
    Location location;
    Vector velocity;
public:
    SolidPellet(const Location &initial, const Vector &velocity);

    Location getLocation() const override;

    void draw(QGraphicsScene *scene) override;

    Vector getVelocity() const override;

    void move(double interval) override;

};


#endif //PELLETS_SOLIDPELLET_H
