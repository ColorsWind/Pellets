//
// Created by colors_wind on 2021/5/28.
//

#include "ExplosiveGrid.h"
#include "../Constants.h"
#include "../Board/Board.h"
#include "../Backend/Collision.h"

ExplosiveGrid::ExplosiveGrid(const Location &point, int health, int damage, int radius) :
        HPGrid(point, health),
        damage(damage),
        radius(radius) {
}

QColor ExplosiveGrid::getColor() const {
    return {200, 200, 150, 60};
}


PelletResult ExplosiveGrid::hit(Board *board, int damage) {
    damage = min(damage, health);
    health -= damage;
    double radius2 = radius * radius;
    double multiDamage = damage * this->damage;
    for (int y = 0; y < Config::board_row; y++)
        for (int x = 0; x < Config::board_col; x++) {
            auto hit = board->getOrNull(x, y);
            if (dynamic_cast<ExplosiveGrid*>(hit)) continue;
            if (!hit || !hit->isAlive()) continue;
            double rDistance2 = location.distance2(hit->getLocation()) / radius2;
            if (rDistance2 < EPS) continue;
            if (rDistance2 < 1.0) rDistance2 = 1.0;
            double realDamage = multiDamage / rDistance2;
            int n = int(realDamage);
            if (board->nextDouble(1.0) < realDamage - n) n++;
            hit->hit(board, n);
        }

    return REFLECT;
}

QString ExplosiveGrid::getLabel() const {
    return "E";
}

