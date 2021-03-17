//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_FIXEDGRID_H
#define PELLETS_FIXEDGRID_H


#include "Grid.h"

class FixedGrid : public Grid {
protected:
    const Location point;


public:
    Location location() const override;

    FixedGrid(const Location &point);
};

#endif //PELLETS_FIXEDGRID_H