//
// Created by colors_wind on 2021/3/15.
//

#include <cmath>
#include "Vector.h"
#include "Location.h"

Vector::Vector(const double velocityX, const double velocityY) : vectorX(velocityX), vectorY(velocityY) {}

Vector Vector::operator*(const double k) const {
    return Vector(vectorX * k, vectorY * k);
}

Vector Vector::normalize(double length) const {
    double k = length / norm();
    return *this * k;
}

Vector Vector::operator-() const {
    return Vector(-vectorX, -vectorY);
}

Vector::Vector(const Location &to, const Location &from) : vectorX(to.pointX - from.pointX),
                                                           vectorY(to.pointY - from.pointY) {
}

double Vector::norm() const {
    return sqrt(vectorX * vectorX + vectorY * vectorY);
}

