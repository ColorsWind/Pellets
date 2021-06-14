//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_COORDINATE_H
#define PELLETS_COORDINATE_H
class Location;
class Vector;

const static double EPS = 1E-3;
/**
 * 向量：可以代表速度，两个位置之间的有向线段。
 */
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
/**
 * 代表弹球、方块所处的位置。
 */
class Location {
public:
    double pointX, pointY;

    Location(double pointX, double pointY);

    Location(const Location &location) = default;

    Location(Location &&location) = default;

    ~Location() = default;

    int getGridX() const;
    int getGridY() const;

    double distance2(const Location &other) const;
    double distance(const Location &other) const;

    Location add(const Vector vector) const;
    Vector toVector() const;

    Location& operator=(const Location &location);

    bool operator==(const Location &rhs) const;

    bool operator!=(const Location &rhs) const;



};


#endif //PELLETS_COORDINATE_H
