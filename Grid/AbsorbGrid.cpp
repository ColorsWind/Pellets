//
// Created by colors_wind on 2021/3/26.
//

#include "Grid.h"

AbsorbGrid::AbsorbGrid(const Location &point, int health) : HPGrid(point, health) {}

PelletResult
AbsorbGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    HPGrid::damageBy(board, damage, scene, pelletSource, gridSource);
    if (pelletSource)
        return DISAPPEAR;
    else
        return NONE;
}

QColor AbsorbGrid::getColor() const {
    return {180, 255, 100, 196};
}

QString AbsorbGrid::getLabel() const {
    return "A";
}
