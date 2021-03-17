//
// Created by colors_wind on 2021/3/15.
//

#include <cmath>
#include "Vector.h"

Vector::Vector(const double velocityX, const double velocityY) : vectorX(velocityX), vectorY(velocityY) {}

Vector Vector::operator*(const double k) const {
    return Vector(vectorX * k, vectorY * k);
}

Vector Vector::normalize(double length) const {
    double k = length / sqrt(vectorX * vectorX + vectorY * vectorY);
    return *this * k;
}

