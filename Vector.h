//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_VECTOR_H
#define PELLETS_VECTOR_H


class Location;
class Vector {
public:
    double vectorX, vectorY;

    Vector(const double velocityX, const double velocityY);
    Vector(const Location& to, const Location& from);

    Vector operator*(const double k) const;

    Vector normalize(double length) const;

    Vector operator-() const;

    double norm() const;
};


#endif //PELLETS_VECTOR_H
