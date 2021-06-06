//
// Created by colors_wind on 2021/3/16.
//

#include "Grid.h"

#include <utility>

Location AbstractGrid::getLocation() const {
    return location;
}

void AbstractGrid::setLocation(Location loc) {
    this->location = loc;
}

AbstractGrid::AbstractGrid(Location point) : location(std::move(point)) {}

Location AbstractGrid::getCentre() const {
    return location.add({25,25});
}

void AbstractGrid::move(Vector vector) {
    location = location.add(vector);
}

int AbstractGrid::getIndexX() const {
    return location.getGridX() / 50;
}

int AbstractGrid::getIndexY() const {
    return location.getGridY() / 50;
}

