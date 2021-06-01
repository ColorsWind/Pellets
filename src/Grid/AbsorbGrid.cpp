//
// Created by colors_wind on 2021/3/26.
//

#include "Grid.h"
#include "Constants.h"

AbsorbGrid::AbsorbGrid(const Location &point, int health) : HPGrid(point, health) {}

PelletResult
AbsorbGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    HPGrid::damageBy(board, damage, scene, pelletSource, gridSource);
    if (pelletSource) {
        pelletSource->remove(scene);
        pelletSource->setLocation(
                {this->location.pointX, Config::board_row * Config::grid_size - Config::pellet_size / 2.0});
    }
    return DISAPPEAR;
}

QColor AbsorbGrid::getColor() const {
    return {180, 255, 100, 196};
}

QString AbsorbGrid::getLabel() const {
    return "A";
}
