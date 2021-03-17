//
// Created by colors_wind on 2021/3/16.
//

#include "FixedGrid.h"

Point FixedGrid::location() const {
    return point;
}

FixedGrid::FixedGrid(const Point &point) : point(point) {}

