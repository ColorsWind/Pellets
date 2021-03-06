//
// Created by colors_wind on 2021/3/15.
//

#include <cmath>
#include "Coordinate.h"

Vector::Vector(const double x, const double y) : vectorX(x), vectorY(y) {}

Vector Vector::operator*(const double k) const {
    return {vectorX * k, vectorY * k};
}

Vector Vector::normalize(const double length) const {
    double k = length / norm();
    return *this * k;
}

Vector Vector::operator-() const {
    return {-vectorX, -vectorY};
}

Vector::Vector(const Location &to, const Location &from) : vectorX(to.pointX - from.pointX),
                                                           vectorY(to.pointY - from.pointY) {
}

double Vector::norm() const {
    return sqrt(vectorX * vectorX + vectorY * vectorY);
}

Vector operator*(const double k, const Vector &vector) {
    return vector.operator*(k);
}

