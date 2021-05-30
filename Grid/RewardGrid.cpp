//
// Created by colors_wind on 2021/3/26.
//

#include "RewardGrid.h"
#include "../Board/Board.h"
#include "../Board/GameBoard.h"
#include "RewardGridItem.h"


PelletResult RewardGrid::hit(Board *board, int damage) {
    health--;
    board->addOwnPellets(1);
    board->addScore(1);

    if (health > 0)
        return REFLECT;
    else
        return NONE;
}

RewardGrid::RewardGrid(const Location &point, int health) :
        HPGrid(point, health) {

}

QColor RewardGrid::getColor() const {
    return {250, 210, 20, 250};
}


GridItem *RewardGrid::initGridItem() {
    return new RewardGridItem(this,
                              getColor(),
                              QString::number(
                                      health));
}

QString RewardGrid::getLabel() const {
    return "R";
}


