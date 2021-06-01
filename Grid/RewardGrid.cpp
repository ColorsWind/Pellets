//
// Created by colors_wind on 2021/3/26.
//

#include "Grid.h"
#include "../Board/Board.h"
#include "../Board/GameBoard.h"
#include "RewardGridItem.h"


PelletResult RewardGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    board->addScore(1);
    HPGrid::damageBy(board, 1, scene, pelletSource, gridSource);
    board->addOwnPellets(1);
    return REFLECT;
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
    return "";
}


