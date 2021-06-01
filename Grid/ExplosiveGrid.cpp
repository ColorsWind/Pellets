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
    return {200, 200, 150, 60};
}


#include <iostream>
using namespace std;
PelletResult
ExplosiveGrid::damageBy(Board *board, int damage, QGraphicsScene *scene, Pellet *pelletSource, Grid *gridSource) {
    damage = min(damage, health);
    cout << "health: " << health << endl;
    cout << "power: " << damage << endl;
    health -= damage;
    board->addScore(damage);
    if (pelletSource) {
        //double radius2 = radius * radius;
        double multiDamage = damage * this->power;
        makeExplosion(board, this->location, multiDamage, radius, scene, nullptr, this);
//        int delta = radius / 50 + 1;
//        int yMin = max(0, this->getIndexY() - radius);
//        int yMax = min(Config::board_row, this->getIndexY() + delta + 1);
//        int xMin = max(0, this->getIndexX() - delta);
//        int xMax = min(Config::board_row, this->getIndexX() + delta + 1);
//        for (int y = yMin; y < yMax; y++)
//            for (int x = xMin; x < xMax; x++) {
//                auto grid = board->getOrNull(x, y);
//                if (!grid || !grid->isAlive()) continue;
//                double rDistance2 = location.distance2(grid->getLocation()) / radius2;
//                if (rDistance2 < EPS) continue;
//                if (rDistance2 < 1.0) rDistance2 = 1.0;
//                double realDamage = multiDamage / rDistance2;
//                int n = int(realDamage);
//                if (board->nextDouble(1.0) < realDamage - n) n++;
//                grid->damageBy(board, n, scene, nullptr, this);
//                cout << n << endl;
//            }
    }

    update(scene);
    return REFLECT;
}

QString ExplosiveGrid::getLabel() const {
    return "E";
}

