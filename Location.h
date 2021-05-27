//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_LOCATION_H
#define PELLETS_LOCATION_H

#include "Vector.h"
const double EPS = 1E-3;
class Vector;
class Location {
public:
    double pointX, pointY;

    Location(double pointX, double pointY);

    int getGridX() const;
    int getGridY() const;

    Location add(const Vector vector) const;
    Vector toVector() const;
    Location& operator=(const Location &location) = default;

};


#endif //PELLETS_LOCATION_H
