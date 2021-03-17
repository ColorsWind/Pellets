//
// Created by colors_wind on 2021/3/16.
//

#ifndef PELLETS_BOARD_H
#define PELLETS_BOARD_H

#include <vector>

#include "Grid/Grid.h"
#include "Pellet/Pellet.h"

class Board {
private:
    const int m;
    const int n;
    Grid*** const grids;
    std::vector<Pellet*> pellets;
    friend class GameBoxWidget;
public:
    Board(int m, int n);
    Grid* at(int x, int y) const;
};


#endif //PELLETS_BOARD_H
