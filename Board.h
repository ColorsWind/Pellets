//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_BOARD_H
#define PELLETS_BOARD_H

#include <vector>

#include "Grid/Grid.h"
#include "Pellet/Pellet.h"
#include "Pellet/SolidPellet.h"

class Board {
protected:
    const int m;
    const int n;
    Grid*** const grids;
    std::vector<Pellet*> existsPellets;
    Location target{0.0,0.0};
    friend class GameBoxWidget;
    int round = 0;
    int launchPellets = 0;
    int maxPellets = 3;
    unsigned int tick = 0;
public:
    Board(int m, int n);
    Grid* at(int x, int y) const;
    Pellet* shoot();

    Location getLaunchLocation() const;

    void nextRound();
};


#endif //PELLETS_BOARD_H
