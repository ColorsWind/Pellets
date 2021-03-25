//
// Created by colors_wind on 2021/3/17.
//

#include "SolidPellet.h"


SolidPellet::SolidPellet(const Location &location, const Vector &velocity) :
        AbstractPellet(location, velocity) {
}

PelletResult SolidPellet::hit(Board *board, Grid *grid) {
    return grid->hit(1);
}
