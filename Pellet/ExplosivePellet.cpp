//
// Created by colors_wind on 2021/3/25.
//

#include <random>
#include "../Board/Board.h"
#include "../Backend/Collision.h"

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



PelletResult ExplosivePellet::damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) {
    handleHit(board, grid);
    makeExplosion(board, this->location, this->damage, this->radius, scene, this, nullptr);
    return TRANSFORM;
}

Pellet *ExplosivePellet::transform(Board *board) {
    if (board->nextDouble(1.0) < 0.5) { // 50%
        int transDamage = rollbackDamage > 0 ? rollbackDamage : (int)round(this->damage);
        return new SolidPellet(this->location, this->velocity, transDamage);
    } else return this; // 50%
}

ExplosivePellet::ExplosivePellet(const Location &location, const Vector &velocity, double damage, double radius,
                                 int rollbackDamage)
        :
        AbstractPellet(location, velocity), damage(damage), radius(radius), rollbackDamage(rollbackDamage) {
}

QColor ExplosivePellet::getColor() const {
    return {255, 128, 128, 250};
}

QString ExplosivePellet::getLabel() const {
    return "";
}
