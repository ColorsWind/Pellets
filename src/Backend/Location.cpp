//
// Created by colors_wind on 2021/3/15.
//

#include "Coordinate.h"
#include <cmath>

Location::Location(const double pointX, const double pointY) : pointX(pointX), pointY(pointY) {}

int Location::getGridX() const {
    return int(pointX + EPS);
}

int Location::getGridY() const {
    return int(pointY + EPS);
}

Location Location::add(const Vector vector) const {
    return Location(pointX + vector.vectorX, pointY + vector.vectorY);
}

Vector Location::toVector() const {
    return {pointX, pointY};
}

double Location::distance2(const Location &other) const {
    double xx = pointX - other.pointX;
    double yy = pointY - other.pointY;
    return xx * xx + yy * yy;
}

double Location::distance(const Location &other) const {
    return sqrt(distance2(other));
}

Location &Location::operator=(const Location &location) {
    this->pointX = location.pointX;
    this->pointY = location.pointY;
    return *this;
}

bool Location::operator==(const Location &rhs) const {
    return abs(pointX - rhs.pointX) < EPS &&
           abs (pointX - rhs.pointX) < EPS;
}

bool Location::operator!=(const Location &rhs) const {
    return !(rhs == *this);
}



