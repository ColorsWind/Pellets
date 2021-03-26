//
// Created by colors_wind on 2021/3/26.
//

#include "RandomPellet.h"
#include "../Board.h"

PelletResult RandomPellet::hit(Board *board, Grid *grid) {
    grid->hit(intGenerator(board->randomEngine));
    return REFLECT;
}

RandomPellet::RandomPellet(const Location &location, const Vector &velocity, int minDamage, int maxDamage)
        : AbstractPellet(location, velocity), intGenerator(minDamage, maxDamage) {
}
