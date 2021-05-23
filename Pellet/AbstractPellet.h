//
// Created by colors_wind on 2021/3/25.
//

#ifndef PELLETS_ABSTRACTPELLET_H
#define PELLETS_ABSTRACTPELLET_H


#include "../Location.h"
#include "Pellet.h"
#include "../Constants.h"
class Board;
class AbstractPellet : public Pellet {
protected:
    Location location;
    Vector velocity;
    PelletItem *pelletItem;
    int hitCount = 0;
public:
    AbstractPellet(const Location &location, const Vector &velocity);

    Location getLocation() const override;
    Location getCentre() const override;
    void setLocation(Location location) override;

    void fixLocationX(Location base) override;

    void fixLocationY(Location base) override;

    void draw(QGraphicsScene *scene) override;
    void remove(QGraphicsScene *scene) override;
    void update(QGraphicsScene *scene) override;

    const PelletItem *getItem() const override;

    Vector getVelocity() const override;
    void move(double interval) override;

    void reflectY() override;
    void reflectX() override;

    void handleHit(Board *board, Grid *grid);

    void leaveBoard() override;

    bool inBoard() override;

    void setVelocity(Vector vector) override;


};


#endif //PELLETS_ABSTRACTPELLET_H
