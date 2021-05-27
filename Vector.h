//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_VECTOR_H
#define PELLETS_VECTOR_H


class Location;
class Vector {
public:
    double vectorX, vectorY;

    Vector(double x, double y);
    Vector(const Location& to, const Location& from);

    Vector operator*(double k) const;

    Vector normalize(double length) const;

    Vector operator-() const;

    double norm() const;

    friend Vector operator*(double k, const Vector &vector);
};


#endif //PELLETS_VECTOR_H
