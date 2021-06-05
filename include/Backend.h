//
// Created by colors_wind on 2021/5/23.
//

#ifndef PELLETS_BACKEND_H
#define PELLETS_BACKEND_H


#include "Constants.h"
#include "Board.h"

const static double PI = acos(-1);


inline int signOfComponent(double component);
inline int locationToIndex(double locationComponent);
int min(int x, int y);
int max(int x, int y);
int randomRound(Board *board, double d);

/**
 * 判断在该维度上是否发送了碰撞
 * @param sign pellet速度的符号
 * @param pelletCentreComponent pellet的坐标
 * @param gridCentreComponent grid的坐标
 * @return 是否发送了碰撞
 */
inline bool isCollided(int sign, double pelletCentreComponent, double gridCentreComponent);

/**
 * 更新弹珠的状态
 * @param pellet
 * @return 碰撞后的结果
 */
PelletResult updatePellet(Board *board, Pellet *pellet, QGraphicsScene *scene, bool showToTarget);


/**
 * 生成下一关的 grid
 * @param board
 * @param grids 当前地图的grids
 * @param place 放置的位置
 */
void nextRound(Board* board, Grid*** grids, Grid** place);

/**
 * 产生一个爆炸
 * @param board
 * @param location
 * @param damage
 * @param radius
 * @param scene
 * @param pelletSource
 * @param gridSource
 */
void makeExplosion(Board *board, Location &location, double damage, int radius, QGraphicsScene *scene,
                   Pellet *pelletSource, Grid *gridSource);
#endif //PELLETS_BACKEND_H
