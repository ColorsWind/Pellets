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
class Pellet;

/**
 * 代表一局游戏的数据结构
 */
class Board {
protected:
    const unsigned int row; // 行
    const unsigned int col; // 列
    Grid*** const grids; // 格子
    std::vector<Pellet*> trackingPellets; // 需要追踪的弹珠
    Location targetLocation; // 上一次鼠标点击的位置
    Location launchLocation; // 弹珠发射的位置
    int round = 0; // 当前回合
    int pelletsToLaunch = 0; // 还未发射的弹珠
    int tick = 0; // 当前的 tick
    int maxPellets = 3; // 玩家拥有的弹珠数
    int score = 0; // 玩家当前的分数

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

    int getRound() const noexcept;

    /**
     * 发射一颗弹珠
     * @return
     */
    Pellet* shoot();

    // 获取玩家拥有的弹珠数量(即每回合可以发射的数量)
    int & getOwnedPellets();


    // 下一关
    virtual void nextRound() = 0;

    // 随机数相关
    double nextDouble(double max=1.0);
    int nextInt(int min, int max);


    const Location &getTargetLocation();

    const Location &getLaunchLocation();

    virtual void addOwnPellets(int n);

    virtual void addScore(int n);

};


#endif //PELLETS_BOARD_H
