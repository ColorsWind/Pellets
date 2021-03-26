//
// Created by colors_wind on 2021/3/26.
//

#include "AbsorbGrid.h"

AbsorbGrid::AbsorbGrid(const Location &point, int health) : HPGrid(point, health) {}

PelletResult AbsorbGrid::hit(Board *board, int damage) {
    HPGrid::hit(nullptr, damage);
    return NONE;
}

QColor AbsorbGrid::getColor() const {
    return {180, 255, 100, 196};
}
