//
// Created by colors_wind on 2021/3/25.
//

#include <random>
#include "../Board.h"
#include "../Constants.h"
#include "ExplosivePellet.h"

int ExplosivePellet::max(int x, int y) {
    if (x > y) return x;
    else return y;
}

int ExplosivePellet::min(int x, int y) {
    if (x < y) return x;
    else return y;
}

int ExplosivePellet::square(int x) {
    return x * x;
}

PelletResult ExplosivePellet::hit(Board *board, Grid *grid) {
    std::uniform_int_distribution<int> intGenerator(1, damage);
    int gridX = grid->getLocation().getGridX();
    int gridY = grid->getLocation().getGridY();
    int minX = max(0, gridX-radius), minY = max(0, gridY-radius);
    int maxX = min(Config::board_col-1, gridX+radius), maxY = min(Config::board_row-1, gridY+radius);
    for (int x=minX;x<=maxX;x++) for (int y=minY;y<=maxY;y++) {
        double realRadius = sqrt(square(x - gridX) + square(y - gridY));
        double damageMax = damage / (realRadius + 1);
        Grid* toDamage = board->at(x, y);
        double realDamage = board->doubleGenerator(board->randomEngine) * damageMax;
        toDamage->hit((int)realDamage);
    }
    return DISAPPEAR;
}

ExplosivePellet::ExplosivePellet(const Location &location, const Vector &velocity, int damage, int radius) :
    AbstractPellet(location, velocity), damage(damage), radius(radius) {
    if (damage < radius) radius = damage;
}

