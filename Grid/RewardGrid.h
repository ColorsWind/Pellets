//
// Created by colors_wind on 2021/3/26.
//

#ifndef PELLETS_REWARDGRID_H
#define PELLETS_REWARDGRID_H


#include "AbstractGrid.h"
#include "GridItem.h"
#include "HPGrid.h"

class RewardGrid : public HPGrid {

public:
    RewardGrid(const Location &point, int health);


    PelletResult hit(Board *board, int damage);

    QColor getColor() const override;

    GridItem *initGridItem() override;

};


#endif //PELLETS_REWARDGRID_H
