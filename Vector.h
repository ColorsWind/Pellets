//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_VECTOR_H
#define PELLETS_VECTOR_H


#include "Point.h"

class Vector {
public:
    const int vectorX, vectorY;

    Vector(const int velocityX, const int velocityY);
    Point add(Point point, double t);
};


#endif //PELLETS_VECTOR_H
