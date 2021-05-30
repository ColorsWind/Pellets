//
// Created by colors_wind on 2021/5/28.
//

#include "RandomGrid.h"
#include "../Board/Board.h"

PelletResult RandomGrid::hit(Board *board, int damage) {
    this -> health -= 1;
    board->addScore(1);
    return TRANSFORM;
}



GridItem *RandomGrid::initGridItem() {
    return new GridItem(this, getColor(), "?");
}

RandomGrid::RandomGrid(const Location &point, int health) : HPGrid(point, health) {
}

QString RandomGrid::getLabel() const {
    return "?";
}

