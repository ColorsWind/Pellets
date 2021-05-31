//
// Created by colors_wind on 2021/5/28.
//

#include "Grid.h"
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


#include <iostream>
using namespace std;
PelletResult ExplosiveGrid::hit(Board *board, int damage) {
    damage = min(damage, health);
    health -= damage;
    double radius2 = radius * radius;
    double multiDamage = damage * this->damage;
    for (int y = 0; y < Config::board_row; y++)
        for (int x = 0; x < Config::board_col; x++) {
            auto grid = board->getOrNull(x, y);
            if (dynamic_cast<ExplosiveGrid*>(grid)) continue;
            if (!grid || !grid->isAlive()) continue;
            double rDistance2 = location.distance2(grid->getLocation()) / radius2;
            if (rDistance2 < EPS) continue;
            if (rDistance2 < 1.0) rDistance2 = 1.0;
            double realDamage = multiDamage / rDistance2;
            int n = int(realDamage);
            if (board->nextDouble(1.0) < realDamage - n) n++;
            grid->hit(board, n);
            cout << n << endl;
        }

    return REFLECT;
}

QString ExplosiveGrid::getLabel() const {
    return "E";
}

