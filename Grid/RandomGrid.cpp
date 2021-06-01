//
// Created by colors_wind on 2021/5/28.
//

#include "Grid.h"
#include "../Board/Board.h"

PelletResult RandomGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    HPGrid::damageBy(board, 1, scene, pelletSource, gridSource);
    if (pelletSource)
        return TRANSFORM;
    else
        return NONE;
}



GridItem *RandomGrid::initGridItem() {
    return new GridItem(this, getColor(), "?");
}

RandomGrid::RandomGrid(const Location &point, int health) : HPGrid(point, health) {
}

QString RandomGrid::getLabel() const {
    return "?";
}

