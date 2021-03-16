//
// Created by colors_wind on 2021/3/15.
//

#include "Point.h"

Point::Point(const double pointX, const double pointY) : pointX(pointX), pointY(pointY) {}

int Point::getGridX() const {
    return int(pointX + EPS);
}

int Point::getGridY() const {
    return int(pointY + EPS);
}
