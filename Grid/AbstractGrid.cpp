//
// Created by colors_wind on 2021/3/16.
//

#include "AbstractGrid.h"

Location AbstractGrid::getLocation() const {
    return location;
}

AbstractGrid::AbstractGrid(const Location &point) : location(point) {}

Location AbstractGrid::getCentre() const {
    return location.add({25,25});
}

void AbstractGrid::move(Vector vector) {
    location = location.add(vector);
}
