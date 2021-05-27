//
// Created by colors_wind on 2021/5/23.
//

#include "Collision.h"
#include <cmath>

bool updatePellet(Board *board, Pellet *pellet, QGraphicsScene *scene, bool showToTarget) {
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
                return true;
            } else {
                return false;
            }
        } else return false;
    } else if (velocity.vectorY < 0 && pelletCentre.pointY - Config::pellet_size / 2 < 0) {
        // 碰到 Y 边界
        pellet->reflectX();
        return true;
    } else if ((velocity.vectorX < 0 && pelletCentre.pointX - Config::pellet_size / 2 < 0)
               || (velocity.vectorX > 0
                   && pelletCentre.pointX + Config::pellet_size / 2 > Config::board_col * Config::grid_size)) {
        // 碰到 X 边界
        pellet->reflectY();
        return true;
    } else if (velocity.vectorY > 0 &&
               pelletCentre.pointY + Config::pellet_size / 2 > Config::board_row * Config::grid_size) {
        // 离开区域
        pellet->leaveBoard();
        return true;
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
        result = pellet->hit(board, gridX);
        if (result == REFLECT) pellet->reflectY();
        gridX->update(scene);
    } else if (gridY && collideY && gridY->isAlive()) { // Y 方向碰撞
        result = pellet->hit(board, gridY);
        if (result == REFLECT) pellet->reflectX();
        gridY->update(scene);
    } else if (gridXY && collideX && collideY && gridXY->isAlive()) { // XY 方向碰撞
        result = pellet->hit(board, gridXY);
        if (result == REFLECT) {
            pellet->reflectX();
            pellet->reflectY();
        }
        gridXY->update(scene);
    }
    pellet->update(scene);
    return result != DISAPPEAR;
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
