//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_GRID_H
#define PELLETS_GRID_H


#include <QPainter>
#include <QGraphicsScene>
#include "../Location.h"
#include "../Pellet/Pellet.h"

class Board;
class Pellet;
enum PelletResult;
class Grid {
public:
    virtual Location getLocation() const = 0;
    virtual void setLocation(const Location location) = 0;
    virtual Location getCentre() const = 0;
    virtual void draw(QGraphicsScene *scene) = 0;
    virtual void remove(QGraphicsScene *scene) = 0;
    virtual void update(QGraphicsScene *scene) = 0;
    virtual void move(Vector vector) = 0;
    virtual bool colliding(Pellet *pellet) = 0;
    virtual bool isAlive() = 0;
    virtual PelletResult hit(Board *board, int damage) = 0;
};


#endif //PELLETS_GRID_H
