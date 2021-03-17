//
// Created by colors_wind on 2021/3/16.
//

#include "FixedGrid.h"

Location FixedGrid::location() const {
    return point;
}

FixedGrid::FixedGrid(const Location &point) : point(point) {}

