//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_FIXEDGRID_H
#define PELLETS_FIXEDGRID_H


#include "Grid.h"

class FixedGrid : public Grid {
protected:
    const Point point;


public:
    Point location() const override;

    FixedGrid(const Point &point);
};

#endif //PELLETS_FIXEDGRID_H