//
// Created by colors_wind on 2021/3/15.
//

#include "Vector.h"

Vector::Vector(const int velocityX, const int velocityY) : vectorX(velocityX), vectorY(velocityY) {}

Point Vector::add(Point point, double t) {
    return Point(point.pointX + vectorX * t, point.pointY + vectorY * t);
}
