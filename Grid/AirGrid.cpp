//
// Created by colors_wind on 2021/3/17.
//

#include "AirGrid.h"

AirGrid::AirGrid(const Location &point) : AbstractGrid(point) {}

void AirGrid::draw(QGraphicsScene *scene) {}

void AirGrid::remove(QGraphicsScene *scene) {}

void AirGrid::update(QGraphicsScene *scene) {}

bool AirGrid::isAlive() {
    return false;
}

PelletResult AirGrid::hit(Board *board, int damage) {
    return PelletResult::NONE;
}
