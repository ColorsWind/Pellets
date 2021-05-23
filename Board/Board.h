//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_BOARD_H
#define PELLETS_BOARD_H

#include <vector>
#include <random>
#include <cmath>
#include "../Grid/Grid.h"
#include "../Pellet/Pellet.h"
#include "../Pellet/SolidPellet.h"
class Pellet;

/**
 * 代表一局游戏的数据结构
 */
class Board {
protected:
    const unsigned int row; // 行
    const unsigned int col; // 列
    Grid*** const grids; // 格子
    std::vector<Pellet*> existsPellets; // 正在移动的弹珠
    Location targetLocation; // 上一次鼠标点击的位置
    Location launchLocation; // 弹珠发射的位置
    unsigned int round = 0; // 当前回合
    unsigned int pelletsToLaunch = 0; // 还未发射的弹珠
    unsigned int tick = 0; // 当前的 tick
    unsigned int maxPellets = 3; // 玩家拥有的弹珠数

    // 随机数相关
    std::mt19937 randomEngine;
    std::uniform_real_distribution<double> doubleGenerator;
public:
    Board(int row, int col);

    /**
     * 带越界检查获取方块, 如果越界则抛出异常.
     * @param x
     * @param y
     * @return
     */
    Grid* at(int x, int y) const;

    /**
     * 带越界检查获取方块, 如果越界返回 nullptr.
     * @param x
     * @param y
     * @return
     */
    Grid *getOrNull(int x, int y) const noexcept;

    /**
     * 发射一颗弹珠
     * @return
     */
    Pellet* shoot();

    // 获取玩家拥有的弹珠数量(即每回合可以发射的数量)
    unsigned int & getOwnedPellets();

    // 下一关
    virtual void nextRound() = 0;

    // 随机数相关
    double nextDouble(double max);
    int nextInt(int min, int max);


};


#endif //PELLETS_BOARD_H
