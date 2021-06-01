//
// Created by colors_wind on 2021/3/26.
//

#include "Board.h"

PelletResult RandomPellet::damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) {
    handleHit(board, grid);
    grid->damageBy(board, board->nextInt(minDamage, maxDamage), scene, this, nullptr);
    return REFLECT;
}

RandomPellet::RandomPellet(const Location &location, const Vector &velocity, int minDamage, int maxDamage, int rollbackDamage)
        : AbstractPellet(location, velocity), minDamage(minDamage), maxDamage(maxDamage), rollbackDamage(rollbackDamage) {
}

Pellet *RandomPellet::transform(Board *board) {
    if (board->nextDouble(1.0) < 0.1) { // 10%
        double transDamage = rollbackDamage > 0 ? rollbackDamage : minDamage;
        return new SolidPellet(this->location, this->velocity, transDamage);
    } else return this; // 90%

}
QColor RandomPellet::getColor() const {
    return {90, 220, 168, 250};
}

QString RandomPellet::getLabel() const {
    return QString();
}


