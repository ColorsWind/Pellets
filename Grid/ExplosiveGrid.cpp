//
// Created by colors_wind on 2021/5/28.
//

#include "Grid.h"
#include "../Constants.h"
#include "../Board/Board.h"
#include "../Backend/Collision.h"

ExplosiveGrid::ExplosiveGrid(const Location &point, int health, int damage, int radius) :
        HPGrid(point, health),
        power(damage),
        radius(radius) {
}

QColor ExplosiveGrid::getColor() const {
    return {255, 160, 115, 60};
}


PelletResult ExplosiveGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    damage = min(damage, health);
    health -= damage;
    board->addScore(damage);
    if (pelletSource) {
        double multiDamage = damage * this->power;
        makeExplosion(board, this->location, multiDamage, radius, scene, nullptr, this);
    }
    update(scene);
    return REFLECT;
}

QString ExplosiveGrid::getLabel() const {
    return "";
}

