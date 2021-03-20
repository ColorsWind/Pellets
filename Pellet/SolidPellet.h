//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_SOLIDPELLET_H
#define PELLETS_SOLIDPELLET_H


#include <QPainter>
#include <QGraphicsScene>
#include "Pellet.h"
#include "../Location.h"
#include "PelletItem.h"

class SolidPellet : public Pellet {
private:
    Location location;
    Vector velocity;
    PelletItem *pelletItem;
public:
    SolidPellet(const Location &initial, const Vector &velocity);

    Location getLocation() const override;

    void draw(QGraphicsScene *scene) override;

    void remove(QGraphicsScene *scene) override;

    void update(QGraphicsScene *scene) override;

    Vector getVelocity() const override;

    void move(double interval) override;

    void reflectY() override;

    void reflectX() override;

    const PelletItem *getItem() const override;


    Location getCentre() const override;

    void setLocation(Location location) override;

    void fixLocationX(Location base) override;

    void fixLocationY(Location base) override;


};


#endif //PELLETS_SOLIDPELLET_H
