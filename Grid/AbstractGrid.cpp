//
// Created by colors_wind on 2021/3/16.
//

#include "AbstractGrid.h"

Location AbstractGrid::getLocation() const {
    return location;
}

void AbstractGrid::setLocation(const Location location) {
    this->location = location;
}

AbstractGrid::AbstractGrid(const Location &point, GridItem *gridItem) : location(point) {
    if (gridItem) this->gridItem = gridItem;
    else this->gridItem = initGridItem();
}

Location AbstractGrid::getCentre() const {
    return location.add({25,25});
}

void AbstractGrid::move(Vector vector) {
    location = location.add(vector);
}

