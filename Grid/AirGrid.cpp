//
// Created by colors_wind on 2021/3/17.
//

#include "AirGrid.h"

AirGrid::AirGrid(const Location &point) : FixedGrid(point) {}

void AirGrid::draw(QGraphicsScene( *scene)) {}

Grid *AirGrid::move(Location point) {
    return new AirGrid(point);
}