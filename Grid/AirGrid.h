//
// Created by colors_wind on 2021/3/17.
//

#ifndef PELLETS_AIRGRID_H
#define PELLETS_AIRGRID_H


#include "FixedGrid.h"

class AirGrid : public FixedGrid {
public:
    AirGrid(const Point &point);

    void draw(QPainter *painter) override;
};


#endif //PELLETS_AIRGRID_H
