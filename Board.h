//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_BOARD_H
#define PELLETS_BOARD_H

#include <vector>
#include <random>

#include "Grid/Grid.h"
#include "Pellet/Pellet.h"
#include "Pellet/SolidPellet.h"
class Pellet;
class Board {
protected:


    const int row;
    const int col;
    Grid*** const grids;
    std::vector<Pellet*> existsPellets;
    Location target{0.0,0.0};
    int round = 0;
    int pelletsToLanuch = 0;
    unsigned int tick = 0;
public:
    int maxPellets = 3;
    Board(int row, int col);
    Grid* at(int x, int y) const;
    Pellet* shoot();

    Location getLaunchLocation() const;

    virtual void nextRound() = 0;

    Grid *atOrNull(int x, int y) const noexcept;

    std::mt19937 randomEngine;
    std::uniform_real_distribution<double> doubleGenerator;
};


#endif //PELLETS_BOARD_H
