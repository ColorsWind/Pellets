//
// Created by colors_wind on 2021/3/26.
//

#include "RewardGrid.h"
#include "../Board/Board.h"
#include "PelletGridItem.h"
#include "../Constants.h"


PelletResult RewardGrid::hit(Board *board, int damage) {
    health--;
    board->maxPellets++;
    if (health > 0)
        return REFLECT;
    else
        return NONE;
}

RewardGrid::RewardGrid(const Location &point, int health) : HPGrid(point, health, new PelletGridItem(this, point.getGridX(),
                                                                                               point.getGridY(), Config::grid_size, Config::grid_size,
                                                                                               getColor(),
                                                                                               QString::number(
                                                                                                       health))) {

}

QColor RewardGrid::getColor() const {
    return {250, 210, 20, 250};
}
