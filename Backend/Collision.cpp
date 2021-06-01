//
// Created by colors_wind on 2021/5/23.
//

#include "Collision.h"
#include "../Grid/Grid.h"
#include <cmath>
#include <algorithm>
#include <random>


PelletResult updatePellet(Board *board, Pellet *pellet, QGraphicsScene *scene, bool showToTarget) {
    Vector velocity = pellet->getVelocity();
    Location pelletCentre = pellet->getCentre();
    // 检查与区域的碰撞
    if (!pellet->inBoard()) {
        // 检查是否需要展示回收动画 第一颗回收的弹珠需要展示
        if (showToTarget) {
            // 检查是否已经移动到回收区域
            if (abs(board->getLaunchLocation().pointX - pellet->getLocation().pointX) > Config::point_error) {
                pellet->setVelocity({signOfComponent(board->getLaunchLocation().pointX - pellet->getLocation().pointX) *
                                     Config::relative_velocity, 0});
                return NONE;
            } else {
                return DISAPPEAR;
            }
        } else return DISAPPEAR;
    } else if (velocity.vectorY < 0 && pelletCentre.pointY - Config::pellet_size / 2 < 0) {
        // 碰到 Y 边界
        pellet->reflectX();
        return REFLECT;
    } else if ((velocity.vectorX < 0 && pelletCentre.pointX - Config::pellet_size / 2 < 0)
               || (velocity.vectorX > 0
                   && pelletCentre.pointX + Config::pellet_size / 2 > Config::board_col * Config::grid_size)) {
        // 碰到 X 边界
        pellet->reflectY();
        return REFLECT;
    } else if (velocity.vectorY > 0 &&
               pelletCentre.pointY + Config::pellet_size / 2 > Config::board_row * Config::grid_size) {
        // 离开区域
        pellet->leaveBoard();
        return NONE;
    }
    // 检查与方块的碰撞
    int signX = signOfComponent(velocity.vectorX);
    int signY = signOfComponent(velocity.vectorY);
    int indexX = locationToIndex(pelletCentre.pointX);
    int indexY = locationToIndex(pelletCentre.pointY);
    Grid *gridX = board->getOrNull(indexX + signX, indexY); // X 方向可能碰撞的方块
    Grid *gridY = board->getOrNull(indexX, indexY + signY); // Y 方向可能碰撞的方块
    Grid *gridXY = board->getOrNull(indexX + signX, indexX + indexY); // XY 方向可能碰撞的方块
    bool collideX = gridX && isCollided(signX, pelletCentre.pointX, gridX->getCentre().pointX); // X 方向确实发生了碰撞
    bool collideY = gridY && isCollided(signY, pelletCentre.pointY, gridY->getCentre().pointY); // Y 方向确实发生了碰撞
    PelletResult result = NONE; // 碰撞的结果
    if (gridX && collideX && gridX->isAlive()) { // X 方向碰撞
        result = pellet->damageGrid(board, gridX, scene);
        if (result == REFLECT || result == TRANSFORM) pellet->reflectY();
        //gridX->update(scene);
    } else if (gridY && collideY && gridY->isAlive()) { // Y 方向碰撞
        result = pellet->damageGrid(board, gridY, scene);
        if (result == REFLECT || result == TRANSFORM) pellet->reflectX();
        //gridY->update(scene);
    } else if (gridXY && collideX && collideY && gridXY->isAlive()) { // XY 方向碰撞
        result = pellet->damageGrid(board, gridXY, scene);
        if (result == REFLECT || result == TRANSFORM) {
            pellet->reflectX();
            pellet->reflectY();
        }
        //gridXY->update(scene);
    }
    pellet->update(scene);
    return result;
}

int signOfComponent(double component) {
    return component > 0 ? 1 :
           (component == 0) ? 0 : -1;
}

int locationToIndex(double locationComponent) {
    return int(locationComponent / Config::grid_size);
}

bool isCollided(int sign, double pelletCentreComponent, double gridCentreComponent) {
    return sign * (pelletCentreComponent + sign * Config::pellet_size / 2) >
           sign * (gridCentreComponent - sign * Config::grid_size / 2);
}

int min(int x, int y) {
    if (x > y) return y;
    else return x;
}

int max(int x, int y) {
    if (x > y) return x;
    else return y;
}


void nextRound(Board *board, Grid ***grids, Grid** place) {
    double possibleReward;
    if (board->getOwnedPellets() > 50)
        possibleReward = 0.5 / (board->getOwnedPellets() - 50);
    else if (board->getOwnedPellets() > 32)
        possibleReward = 1.0 - 0.5 * (board->getOwnedPellets() - 32 ) / 18;
    else
        possibleReward = 1.0;
    int healthReward = 1;
    // board->nextInt(1, board->getRound() / 100 + 1)

    double possibleRandom;
    if (board->getRound() < 50)
        possibleRandom = 0.5;
    else
        possibleReward = abs(cos(double(board->getRound() % 16) * pi / 17));
    int healthRandom = board->nextInt(2, board->getRound() / 100 + 5);

    double possibleAbsorb;
    if (board->getOwnedPellets() > 30)
        possibleAbsorb = board->getOwnedPellets() / 1000.0;
    else
        possibleAbsorb = 0;
    int healthAbsorb = max(board->nextInt(1, board->getRound() / 300 + 1), 3);

    double possibleExplosive;
    if (board->getRound() > 30)
        possibleExplosive = possibleAbsorb * 2 + 0.2;
    else
        possibleExplosive = 0.05;
    int healthExplosive = max(board->nextInt(1, board->getRound() / 100 + 2), 5);
    int damageExplosive = max(1, board->getRound() / 5);
    double radiusExplosive;
    if (board->getRound() > 100)
        radiusExplosive = (board->nextDouble(3) + 1) * Config::grid_size;
    else
        radiusExplosive = (board->nextDouble(2) + 1) * Config::grid_size;


    int maxHealth = 2 * board->getRound() + 1;

    int empty;
    if (board->getRound() > 500)
        empty = board->nextInt(0, 2);
    else if (board->getRound() > 100)
        empty = board->nextInt(1, 3);
    else if (board->getRound() > 30)
        empty = board->nextInt(1, 4);
    else
        empty = board->nextInt(1, 5);

    int curr = 0;


    possibleReward = 0;
    possibleRandom = 1;
    possibleExplosive = 1;
    if (board->nextDouble(1.0) < possibleReward) {
        place[curr++] = new RewardGrid({0,0}, healthReward);
    } else if (board->nextDouble(1.0) < possibleRandom) {
        place[curr++] = new RandomGrid({0,0}, healthRandom);
    }

    if (board->nextDouble() < possibleAbsorb) {
        place[curr++] = new AbsorbGrid({0, 0}, healthAbsorb);
    }
    if (board->nextDouble() < possibleExplosive) {
        place[curr++] = new ExplosiveGrid({0,0}, healthExplosive, damageExplosive, radiusExplosive);
    }

    for (int i=0;i<empty;i++) {
        place[curr++] = new AirGrid({0,0 });
    }

    while(curr < Config::board_col) {
        place[curr++] = new HPGrid({0, 0}, board->nextInt(1, maxHealth));
    }

    std::shuffle(place, place + Config::board_col, std::mt19937(std::random_device()()));
}




void makeExplosion(Board *board, Location &location, double damage, int radius, QGraphicsScene *scene, Pellet *pelletSource,
              Grid *gridSource) {
    double radius2 = radius * radius;
    int delta = radius / 50 + 1;
    int yMin = max(0, int(location.pointY / 50) - radius);
    int yMax = min(Config::board_row, int(location.pointY / 50) + delta + 1);
    int xMin = max(0, int(location.pointX / 50) - delta);
    int xMax = min(Config::board_row, int(location.pointX / 50) + delta + 1);
    for (int y = yMin; y < yMax; y++)
        for (int x = xMin; x < xMax; x++) {
            auto grid = board->getOrNull(x, y);
            if (!grid || !grid->isAlive()) continue;
            double rDistance2 = location.distance2(grid->getLocation()) / radius2;
            if (rDistance2 < EPS) continue;
            if (rDistance2 < 1.0) rDistance2 = 1.0;
            double realDamage = damage / rDistance2;
            int n = int(realDamage);
            if (board->nextDouble(1.0) < realDamage - n) n++;
            grid->damageBy(board, n, scene, pelletSource, gridSource);
        }

}
