//
// Created by colors_wind on 2021/3/25.
//

#include <random>
#include "../Board/Board.h"
#include "../Constants.h"

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
    handleHit(board, grid);
    int gridX = grid->getLocation().getGridX();
    int gridY = grid->getLocation().getGridY();
    int minX = max(0, gridX - radius), minY = max(0, gridY - radius);
    int maxX = min(Config::board_col - 1, gridX + radius), maxY = min(Config::board_row - 1, gridY + radius);
    for (int x = minX; x <= maxX; x++)
        for (int y = minY; y <= maxY; y++) {
            double realRadius = sqrt(square(x - gridX) + square(y - gridY));
            double damageMax = damage / (realRadius + 1);
            Grid *toDamage = board->at(x, y);
            double realDamage = board->nextDouble(damageMax);
            toDamage->hit(board, (int) realDamage);
        }
    return DISAPPEAR;
}

Pellet *ExplosivePellet::transform(Board *board) {
    if (board->nextDouble(1.0) < 0.3) { // 30%
        double transDamage = rollbackDamage > 0 ? rollbackDamage : (int)round(this->damage);
        return new SolidPellet(this->location, this->velocity, transDamage);
    } else return this; // 70%
}

ExplosivePellet::ExplosivePellet(const Location &location, const Vector &velocity, double damage, double radius,
                                 int rollbackDamage)
        :
        AbstractPellet(location, velocity), damage(damage), radius(radius), rollbackDamage(rollbackDamage) {
}

QColor ExplosivePellet::getColor() const {
    return {135, 236, 74, 250};
}

QString ExplosivePellet::getLabel() const {
    return "";
}
