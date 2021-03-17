//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_GRID_H
#define PELLETS_GRID_H


#include <QPainter>
#include "../Location.h"

class Grid {
public:
    virtual Location location() const = 0;
    virtual void draw(QPainter* painter) = 0;
    virtual Grid* move(Location point) = 0;

};


#endif //PELLETS_GRID_H
