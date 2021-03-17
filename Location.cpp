//
// Created by colors_wind on 2021/3/15.
//

#include "Location.h"

Location::Location(const double pointX, const double pointY) : pointX(pointX), pointY(pointY) {}

int Location::getGridX() const {
    return int(pointX + EPS);
}

int Location::getGridY() const {
    return int(pointY + EPS);
}

Location Location::add(Vector vector) const {
    return Location(pointX + vector.vectorX, pointY + vector.vectorY);
}

