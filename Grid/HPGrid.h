//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_HPGRID_H
#define PELLETS_HPGRID_H


#include "FixedGrid.h"

class HPGrid : public FixedGrid {
protected:
    int health;
public:
    void draw(QPainter* painter) override;

    HPGrid(const Location &point, int health);

    Grid *move(Location point) override;
};


#endif //PELLETS_HPGRID_H
