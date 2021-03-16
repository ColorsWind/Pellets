//
// Created by colors_wind on 2021/3/15.
//

#ifndef PELLETS_POINT_H
#define PELLETS_POINT_H

const double EPS = 1E-3;
class Point {
public:
    const double pointX, pointY;

    Point(const double pointX, const double pointY);

    int getGridX() const;
    int getGridY() const;
};


#endif //PELLETS_POINT_H
