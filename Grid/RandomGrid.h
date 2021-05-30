//
// Created by colors_wind on 2021/5/28.
//

#ifndef PELLETS_RANDOMGRID_H
#define PELLETS_RANDOMGRID_H


#include "HPGrid.h"

class RandomGrid : public HPGrid {

public:
    RandomGrid(const Location &point, int health);

    PelletResult hit(Board *board, int damage) override;

    GridItem *initGridItem() override;


    QString getLabel() const override;
};


#endif //PELLETS_RANDOMGRID_H
