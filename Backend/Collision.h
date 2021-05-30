//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_COLLISION_H
#define PELLETS_COLLISION_H


#include "../Constants.h"
#include "../Board/Board.h"

const static double pi = acos(-1);
inline int signOfComponent(double component);
inline int locationToIndex(double locationComponent);
inline bool isCollided(int sign, double pelletCentreComponent, double gridCentreComponent);

/**
 * 更新弹珠的状态
 * @param pellet
 * @return 更新后弹珠是否存在
 */
PelletResult updatePellet(Board *board, Pellet *pellet, QGraphicsScene *scene, bool showToTarget);

int min(int x, int y);

int max(int x, int y);

void nextRound(Board* board, Grid*** grids, Grid** place);
#endif //PELLETS_COLLISION_H
