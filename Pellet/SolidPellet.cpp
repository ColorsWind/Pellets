//
// Created by colors_wind on 2021/3/17.
//
#include <cmath>
#include "Pellet.h"
#include "../Board/Board.h"
#include "../Backend/Collision.h"

SolidPellet::SolidPellet(const Location &location, const Vector &velocity, int damage) :
        AbstractPellet(location, velocity), damage(damage) {
}

PelletResult SolidPellet::damageGrid(Board *board, Grid *grid, QGraphicsScene *scene) {
    handleHit(board, grid);
    return grid->damageBy(board, damage, scene, this, nullptr);
}

Pellet *SolidPellet::transform(Board *board) {
    double r = board->nextDouble(1.0);
    Location &loc = this->location;
    Vector &vec = this->velocity;
    if (r > 0.7) { // 30%
        double newDamage = this->damage * board->nextDouble(3);
        double radius = fmin((board->getRound() / 100 + 1) * board->nextDouble(1.0), 1.5) * Config::grid_size;
        return new ExplosivePellet(loc, vec, round(newDamage), radius, this->damage);
    } else if (r > 0.2) { // 50%
        double lowerDamage = this->damage;
        double upperDamage = this->damage * 2;
        return new RandomPellet(loc, vec, lowerDamage, upperDamage, this->damage);
    } else { // 20%
        int deltaDamage = min(10, board->nextInt(0, board->getRound() / 100) + 1);
        this->damage += deltaDamage;
        return this;
    }
}

QColor SolidPellet::getColor() const {
    return {250, 210, 20, 250};
}

QString SolidPellet::getLabel() const {
    return "";
}
